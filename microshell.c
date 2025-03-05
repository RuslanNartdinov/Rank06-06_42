#include <string.h>    // для strcmp
#include <unistd.h>    // для write, fork, chdir, pipe, dup2, close
#include <sys/wait.h>  // для waitpid, WIFEXITED, WEXITSTATUS

// Функция err просто выводит строку в stderr (дескриптор 2) и возвращает 1
int err(char *str)
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

// Функция cd реализует команду "cd"
// argv - это список аргументов, i - позиция, на которой либо pipe/; либо конец
int cd(char **argv, int i)
{
    // Проверяем, что аргументов ровно 2 (cd + путь)
    if (i != 2)
        return err("error: cd: bad arguments\n");
    // Если chdir вернул -1, значит не удалось перейти в каталог - выводим ошибку
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    // Если всё хорошо - возвращаем 0
    return 0;
}

// Функция exec отвечает за запуск команды (в том числе с учётом пайпов)
int exec(char **argv, char **envp, int i)
{
    int fd[2];        // файловые дескрипторы для pipe
    int status;       // для waitpid
    // has_pipe определяем, есть ли в argv[i] символ "|" - значит будет пайп
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    // Если нет пайпа и команда - это cd, сразу выполняем cd
    if (!has_pipe && !strcmp(*argv, "cd"))
        return cd(argv, i);

    // Если есть пайп, пробуем создать pipe(fd)
    if (has_pipe)
        if (pipe(fd) == -1)
            return err("error: fatal\n");

    // Делаем fork
    int pid = fork();
    if (pid == 0)
    {
        // В дочернем процессе:
        argv[i] = 0; // обрезаем массив argv на позиции i, чтобы execve знал конец

        // Если есть пайп, переходим stdout → fd[1], закрываем ненужные дескрипторы
        if (has_pipe) {
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
                return err("error: fatal\n");
        }

        // Если команда cd, то выполняем её (хотя выше уже проверяли, но на всякий случай)
        if (!strcmp(*argv, "cd"))
            return cd(argv, i);

        // Запускаем execve, если execve не сработает → выводим ошибку
        execve(*argv, argv, envp);
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    // В родительском процессе ждём завершения ребёнка
    waitpid(pid, &status, 0);

    // Если был пайп, перенаправляем stdin ← fd[0], закрываем ненужные дескрипторы
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");

    // Возвращаем код возврата ребёнка (0 или 1), если он завершился нормально
    return WIFEXITED(status) && WEXITSTATUS(status);
}

// Главная функция
int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    i = 0;
    if (argc > 1)
    {
        // Пока не пройдёмся по всем аргументам
        while (argv[i] && argv[++i])
        {
            // Смещаем argv на i (пропускаем уже обработанные)
            argv += i;
            i = 0;

            // До первого "|" или ";" (или конца массива) увеличиваем i
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;

            // Если действительно есть команда (i > 0), то выполняем её
            if (i > 0)
                status = exec(argv, envp, i);
        }
    }
    return status;
}
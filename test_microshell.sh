#!/bin/bash

# ========== 1. Компиляция ==========
echo "Compiling microshell.c..."
gcc -Wall -Wextra -Werror microshell_practice.c -o microshell 2>compile_errors.log
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции! Смотри файл compile_errors.log"
    exit 1
fi
echo "Компиляция прошла успешно."
echo

# -----------------------------------------------------------------------------
# Вспомогательная функция для сравнения вывода с ожидаемым
# ПАРАМЕТРЫ:
#   1) Описание теста (строка)
#   2..N) Аргументы, которые передадутся программе ./microshell
# Глобальные переменные, используемые внутри:
#   EXPECTED_OUTPUT  - ожидаемый (эталонный) вывод (строка)
#   EXPECTED_EXIT    - ожидаемый код возврата (число)
# -----------------------------------------------------------------------------
run_test() {
    local test_name="$1"
    shift

    echo "=== Тест: $test_name ==="
    echo "Запуск: ./microshell $@"
    
    # Запустим программу и поймаем stdout + stderr вместе (2>&1)
    local output
    output=$(./microshell "$@" 2>&1)
    local ret=$?

    # Сравниваем выход с ожидаемым
    # Обратите внимание, что в bash сравнение строк с переносами надо аккуратно обрабатывать.
    # Здесь используем обычное строковое сравнение.
    # Если есть сложные многострочные данные, лучше сохранять в файлы и делать `diff`.
    
    if [ "$output" == "$EXPECTED_OUTPUT" ] && [ $ret -eq $EXPECTED_EXIT ]; then
        echo "да"
    else
        echo "нет"
        echo "----- Ожидалось:"
        echo -e "$EXPECTED_OUTPUT"
        echo "(код возврата: $EXPECTED_EXIT)"
        echo "----- Получено:"
        echo -e "$output"
        echo "(код возврата: $ret)"
    fi
    echo
}

# -----------------------------------------------------------------------------
# ========== 2. ОПРЕДЕЛЕНИЕ ТЕСТОВ ==========
# Ниже несколько примеров. Вы можете их расширять, редактировать, дополнять.
# -----------------------------------------------------------------------------

# --- ТЕСТ 1: Без аргументов ---
# По коду microshell, если запустить без аргументов, программа выведет:
#   "argc: 1\n"   (поскольку argv[0] — это сама программа, значит argc = 1)
# и выйдет с кодом 0.
EXPECTED_OUTPUT="argc: 1"
EXPECTED_EXIT=0
run_test "No arguments" 

# --- ТЕСТ 2: cd без аргументов ---
# Ожидается:
#   "argc: 2\nerror: cd: bad arguments\n"
# и код возврата 1 (функция err всегда возвращает 1).
EXPECTED_OUTPUT="argc: 2
error: cd: bad arguments"
EXPECTED_EXIT=1
run_test "cd without argument" cd

# --- ТЕСТ 3: cd с несуществующей директорией ---
# Ожидается:
#   "argc: 2\nerror: cd: cannot change directory to \nnot_a_real_path\n"
# (или слияние строк, в зависимости от того, как в коде печатается).
# Код выхода: 1
EXPECTED_OUTPUT="argc: 2
error: cd: cannot change directory to not_a_real_path
"
# Обратите внимание, что ваш код может вывести это чуть иначе
# (например, две отдельных ошибки подряд). Проверьте, как именно формируется строка.
EXPECTED_EXIT=1
run_test "cd invalid path" cd not_a_real_path

# --- ТЕСТ 4: cd . ---
# Должно быть:
#   "argc: 2\n" + если chdir('.') успешен, то ошибки не будет
# Код возврата: 0
EXPECTED_OUTPUT="argc: 2"
EXPECTED_EXIT=0
run_test "cd valid path" cd .

# --- ТЕСТ 5: Обычная команда echo ---
# Пример: ./microshell /bin/echo Hello
# Ожидаем:
#   "argc: 2\nHello\n"
# Код возврата: 0
EXPECTED_OUTPUT="argc: 2
Hello"
EXPECTED_EXIT=0
run_test "Single command echo" /bin/echo Hello

# --- ТЕСТ 6: Пайп "echo Hello | grep l" ---
# Аргументы для microshell: "/bin/echo" "Hello" "|" "/bin/grep" "l"
# Ожидаемый вывод (пример):
#   "argc: 5\nHello\n"
#   а затем выведет всё, где 'l' есть — т.е. "Hello".
#   На деле "echo Hello" даст "Hello\n", grep 'l' пропустит строки с 'l' => "Hello\n"
# Код возврата 0 (если всё правильно).
EXPECTED_OUTPUT="argc: 5
Hello"
EXPECTED_EXIT=0
run_test "Pipe echo | grep" /bin/echo Hello "|" /bin/grep l

# --- ТЕСТ 7: Несколько команд через ";" ---
# /bin/echo first ";" /bin/echo second
# - Первая команда echo first => "first"
# - Вторая echo second => "second"
# Итого должно получиться:
#   "argc: 4\nfirst\nsecond\n"
# Код возврата: 0 (если всё ок)
EXPECTED_OUTPUT="argc: 4
first
second"
EXPECTED_EXIT=0
run_test "Semicolon commands" /bin/echo first ";" /bin/echo second

# --- ТЕСТ 8: Смешанный пример: "echo Hello | tr '[:upper:]' '[:lower:]' ; echo Done"
# /bin/echo Hello "|" /usr/bin/tr '[:upper:]' '[:lower:]' ";" /bin/echo Done
# Ожидается:
#   "argc: 7\nhello\nDone\n"
EXPECTED_OUTPUT="argc: 7
hello
Done"
EXPECTED_EXIT=0
run_test "Pipe + Semicolon" /bin/echo Hello "|" /usr/bin/tr '[:upper:]' '[:lower:]' ";" /bin/echo Done

# --- ТЕСТ 9: Несколько команд: "echo 1 ; echo 2 ; echo 3"
# /bin/echo 1 ";" /bin/echo 2 ";" /bin/echo 3
EXPECTED_OUTPUT="argc: 6
1
2
3"
EXPECTED_EXIT=0
run_test "Multiple commands" /bin/echo 1 ";" /bin/echo 2 ";" /bin/echo 3

# При необходимости добавляйте свои тесты:
# run_test "Название" <арг1> <арг2> ...

echo "Тестирование завершено!"
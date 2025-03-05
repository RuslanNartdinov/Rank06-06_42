#include <iostream>
#include <fstream>
#include <string>

static void replaceAll(std::string &text, const std::string &s1, const std::string &s2) {
    // Можно, например, искать через find()
    // и вручную собирать новую строку.

    if (s1.empty())
        return;

    std::string result;
    size_t startPos = 0;
    while (true) {
        size_t pos = text.find(s1, startPos);
        if (pos == std::string::npos) {
            // Добавляем остаток и выходим
            result += text.substr(startPos);
            break;
        }
        // Добавляем кусок до s1
        result += text.substr(startPos, pos - startPos);
        // Добавляем s2 вместо s1
        result += s2;
        // Смещаемся дальше
        startPos = pos + s1.size();
    }
    text = result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Открыть входной файл
    std::ifstream ifs(filename.c_str());
    if (!ifs) {
        std::cerr << "Error: cannot open input file.\n";
        return 1;
    }

    // Считать всё содержимое в одну строку (или можно построчно)
    std::string content((std::istreambuf_iterator<char>(ifs)),
                         std::istreambuf_iterator<char>());
    ifs.close();

    // Заменить все вхождения s1 на s2
    replaceAll(content, s1, s2);

    // Открыть выходной файл <filename>.replace
    std::string outName = filename + ".replace";
    std::ofstream ofs(outName.c_str());
    if (!ofs) {
        std::cerr << "Error: cannot open output file.\n";
        return 1;
    }

    ofs << content;
    ofs.close();

    return 0;
}
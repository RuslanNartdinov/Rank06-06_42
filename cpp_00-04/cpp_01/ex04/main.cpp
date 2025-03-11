#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAll(std::string &str, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
	{
		return;
	}

	size_t position = 0;
	while ((position = str.find(s1, position)) != std::string::npos)
	{
		str.erase(position, s1.length());
		str.insert(position, s2);
		position += s2.length();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: filename, s1 or s2 is empty." << std::endl;
		return 1;
	}
	// ifstream - класс <fstream> предназначенный для работы с потоками ввода из файлов
	// ostringstream - класс <sstream> предназначенный для создания строкового потока вывода. Он позволяет накапливать данные в буфере, который затем можно преобразовать в объект типа std::string
	// usage:
	// std::ostringstream oss;
	// oss << "Hello, " << "world!";
	// std::string result = oss.str();
	// rdbuf возвращает указатель на внутренний буфер потока
	// В контексте файловых потоков (например, std::ifstream), вызов inputFile.rdbuf() возвращает указатель на объект, который содержит данные файла.
	// usage:
	// std::ifstream inputFile("example.txt");
	// std::ostringstream oss;
	// oss << inputFile.rdbuf(); <- копирует всё содержимое файла в поток oss копирует все содержимое файла в поток

	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}
	std::ostringstream oss;
	oss << inputFile.rdbuf();
	std::string content = oss.str();
	inputFile.close();
	replaceAll(content, s1, s2);

	std::string outputFilename = filename + ".replace";

	// ofstream - Это класс из заголовочного файла <fstream>, предназначенный для работы с потоками вывода в файлы
	// Объект std::ofstream открывает файл для записи. Данные, записанные в поток с помощью оператора <<, записываются в файл.
	// Пример: outputFile << content;
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		std::cerr << "Error: could not create file " << outputFilename << std::endl;
		return 1;
	}

	outputFile << content;
	outputFile.close();

	std::cout << "Replacement done. Output file: " << outputFilename << std::endl;
	return 0;
}
#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    // Адреса
    std::cout << "Address of brain    : " << &brain << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in stringREF: " << &stringREF << std::endl;

    // Значения
    std::cout << "Value of brain      : " << brain << std::endl;
    std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF: " << stringREF << std::endl;

    return 0;
}
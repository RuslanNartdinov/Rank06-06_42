#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "Creating an Animal..." << std::endl;
    Animal *meta = new Animal();

    std::cout << "\nCreating a Dog..." << std::endl;
    Animal *dog = new Dog();

    std::cout << "\nCreating a Cat..." << std::endl;
    Animal *cat = new Cat();

    std::cout << "\nAnimal type: " << meta->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    meta->makeSound(); // generic sound
    dog->makeSound();  // Woof!
    cat->makeSound();  // Meow!

    std::cout << "\nDeleting everything:" << std::endl;
    delete meta;
    delete dog;
    delete cat;

    return 0;
}
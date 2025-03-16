#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
	std::cout << "Array test" << std::endl;
	Animal *animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
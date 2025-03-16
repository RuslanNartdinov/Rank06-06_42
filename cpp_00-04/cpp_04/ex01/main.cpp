#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;
	std::cout << "Array test" << std::endl;
	Animal *animals[6];
	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();
	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();
	for (int k = 0; k < 6; k++)
		delete animals[k];
	std::cout << "Deep copy test" << std::endl;
	Dog *d1 = new Dog();
	d1->setIdea(0, "food");
	Dog *d2 = new Dog(*d1);
	std::cout << d1->getIdea(0) << std::endl;
	std::cout << d2->getIdea(0) << std::endl;
	d1->setIdea(0, "ball");
	std::cout << d1->getIdea(0) << std::endl;
	std::cout << d2->getIdea(0) << std::endl;
	delete d1;
	delete d2;
	return 0;
}
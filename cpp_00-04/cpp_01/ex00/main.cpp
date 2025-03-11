#include "Zombie.hpp"
#include <iostream>

int main(){
	std::cout << "heap memory (newZombie)" << std::endl;
	Zombie *heapZombie = newZombie("(heap zombie)");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "stack memory (randomChump)";
	randomChump("(stack zombie)");

	return 0;
}
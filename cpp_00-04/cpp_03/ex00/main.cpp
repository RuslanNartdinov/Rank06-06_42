#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");
	a.attack("B");
	b.takeDamage(0);
	b.beRepaired(5);
	for (int i = 0; i < 11; i++)
		a.attack("B");
	a.beRepaired(1);
	for (int i = 0; i < 11; i++)
		b.takeDamage(2);
	b.attack("A");
	return 0;
}
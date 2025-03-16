#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Scavvy");
	scav.attack("target");
	scav.guardGate();
	scav.beRepaired(10);
	scav.takeDamage(20);
	return 0;
}
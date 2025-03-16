#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");
	FragTrap f("Fraggy");

	c.attack("an enemy");
	s.attack("an enemy");
	f.attack("an enemy");

	c.beRepaired(5);
	s.beRepaired(10);
	f.beRepaired(15);

	c.takeDamage(5);
	s.takeDamage(20);
	f.takeDamage(40);

	s.guardGate();
	f.highFivesGuys();
	return 0;
}
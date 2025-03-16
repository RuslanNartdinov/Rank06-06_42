#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &n) : name(n), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " copy constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << name << " assigned" << std::endl;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		if (hitPoints < 0)
			hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " damage, hit points now " << hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is already destroyed" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself, gaining "
				  << amount << " hit points, hit points now " << hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot be repaired" << std::endl;
}
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other)
	: _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
	std::cout << "Copy constructor called" << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is taking " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
		std::cout << "ClapTrap " << _name << " is being repaired by " << amount << " points!" << std::endl;
}

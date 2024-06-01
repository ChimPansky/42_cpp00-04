#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "String constructor called" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
	std::cout << "Copy constructor called" << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " cannot attack, because it doesn't "
		<< "have any hitpoints left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " cannot take any more damage, because it doesn't "
			<< "have any hitpoints left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is taking " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " cannot be repaired, because it doesn't "
			<< "have any hitpoints left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is being repaired by " << amount << " points!" << std::endl;
	_hitPoints += amount;
}

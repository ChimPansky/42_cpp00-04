#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

const std::string ClapTrap::_className = "Claptrap";

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

// private methods:
bool	ClapTrap::_isInactive() {
	return (_hitPoints < 1 || _energyPoints < 1);
}

void	ClapTrap::_printMessage(Message message, const std::string& target, unsigned int amount) {
	(void)target;
	(void)amount;
	std::cout << _className << " " << std::left << std::setw(10) << _name << ": ";
	if (_hitPoints < 1) {
		std::cout << "Not enough hitpoints!" << std::endl;
		return;
	}
	if (_energyPoints < 1) {
		std::cout << "Not enough energy points!" << std::endl;
		return;
	}
	switch (message) {
		case Attack:
			std::cout << "Attacks " << target;
			break;
		case TakeDamage:
			std::cout << "Is taking " << amount << " damage. " << _hitPoints - amount << " hitpoints remaining.";
			break;
		case BeRepaired:
			std::cout << "Is being repaired for " << amount << " hitpoints " << _hitPoints + amount << "remaining.";
			break;
		default:
			std::cout << "Performs unknown action ";
	}
	std::cout << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	_printMessage(Attack, target, _attackDamage);
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_printMessage(TakeDamage, NULL, amount);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	_printMessage(BeRepaired, NULL, amount);
	if (_isInactive())
		//////////////////
	_energyPoints--;
	_hitPoints += amount;
	if (_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " cannot be repaired, because it doesn't "
			<< "have any hitpoints left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is being repaired by " << amount << " points!" << std::endl;
	_hitPoints += amount;
}

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

const std::string ScavTrap::_className = "Scavtrap";

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject) {
	outStream << YELLOW_COLOR << scavTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

ScavTrap::ScavTrap()
	: ClapTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
		_name = SCAV_DEFAULT_NAME;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name) {
		std::cout << _className << ": String constructor called" << std::endl;
	_name = name;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public methods:
std::string	ScavTrap::getClassName() const {
	return (_className);
}

std::string ScavTrap::getName() const {
	return (_name);
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "<" << _className << " method attack()>: ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Attack, &target);
		return ;
	}
	_mana--;
	_printAction(Attack, _damage, &target);
}

void	ScavTrap::guardGate() {
	std::cout << "<" << _className << " method guardGate()>: ";
	std::cout << *this << " is now in gate keeper mode." << std::endl;
}

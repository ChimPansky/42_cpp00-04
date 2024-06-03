#include "ScavTrap.hpp"
#include <iostream>
#include <string>

const std::string ScavTrap::_className = "Scavtrap";

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject) {
	outStream << scavTrapObject.getClassName() << " " << YELLOW_COLOR << scavTrapObject.getName();
	return (outStream);
}

void	ScavTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = SCAV_DEFAULT_HP;
	_mana = SCAV_DEFAULT_MANA;
	_damage = SCAV_DEFAULT_DAMAGE;
}

ScavTrap::ScavTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
		_initialize(SCAV_DEFAULT_NAME);
}

ScavTrap::ScavTrap(const std::string& name) {
		std::cout << _className << ": String constructor called" << std::endl;
		_initialize(name);
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Attack, &target);
		return ;
	}
	_mana--;
	std::cout << *this << CYAN_COLOR << " attacks " << YELLOW_COLOR << target << RESET_COLOR << " -> ";
	_printHpAndMana();
	std::cout  << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public Getters:
std::string	ScavTrap::getClassName() const {
	return (_className);
}

std::string ScavTrap::getName() const {
	return (_name);
}

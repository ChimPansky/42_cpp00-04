#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

const std::string DiamondTrap::_className = "Diamondtrap";

std::ostream& operator<<(std::ostream& outStream, const DiamondTrap& diamondTrapObject) {
	outStream << YELLOW_COLOR << diamondTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

DiamondTrap::DiamondTrap()
	: ClapTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
	_initialize(_className + "_Default");
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),  FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
		std::cout << _className << ": String constructor called" << std::endl;
	_initialize(name);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::_name = other.ClapTrap::_name;
		_name = other._name;
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public methods:
std::string	DiamondTrap::getClassName() const {
	return (_className);
}

std::string DiamondTrap::getName() const {
	return (DiamondTrap::_name);
}

void	DiamondTrap::whoAmI() {
	std::cout << "<" << _className << " method whoAmI()>: ";
	std::cout << _className << " name: " << _name << "; "
		<< "ScavTrap name: " << _name
		<< "ClapTrap name: " << ClapTrap::_name << std::endl;
}

// private methods:
void	DiamondTrap::_initialize(const std::string& name) {
	//ClapTrap::_name = name + "_clap_name";
	_name = name;
	_hp = FragTrap::_defaultHp;
	_mana = ScavTrap::_defaultMana;
	_damage = FragTrap::_defaultDamage;
}

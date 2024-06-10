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

DiamondTrap::DiamondTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
		_initialize(DIAMOND_DEFAULT_NAME);
}

DiamondTrap::DiamondTrap(const std::string& name) {
		std::cout << _className << ": String constructor called" << std::endl;
		ClapTrap::_name = name + "_clap_name";
		_initialize(name);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: FragTrap(other), ScavTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
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

// private methods:
void	DiamondTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = FRAG_DEFAULT_HP;
	_mana = SCAV_DEFAULT_MANA;
	_damage = FRAG_DEFAULT_DAMAGE;
}

// public Getters:
std::string	DiamondTrap::getClassName() const {
	return (_className);
}

std::string DiamondTrap::getName() const {
	return (DiamondTrap::_name);
}

// public methods:
void	DiamondTrap::whoAmI() {
	std::cout << "<" << _className << " method whoAmI()>: ";
	std::cout << _className << " name: " << _name << "; "
		<< "ClapTrap name: " << ClapTrap::_name << std::endl;
}

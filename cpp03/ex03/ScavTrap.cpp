#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

const std::string ScavTrap::_className = "Scavtrap";

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject) {
	outStream << YELLOW_COLOR << scavTrapObject.getName() << RESET_COLOR;
	return (outStream);
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

ScavTrap::~ScavTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// private methods:
void	ScavTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = SCAV_DEFAULT_HP;
	_mana = SCAV_DEFAULT_MANA;
	_damage = SCAV_DEFAULT_DAMAGE;
}

// public Getters:
std::string	ScavTrap::getClassName() const {
	return (_className);
}

std::string ScavTrap::getName() const {
	return (_name);
}

// public methods:
void	ScavTrap::attack(const std::string& target) {
	std::cout << "<" << _className << " method attack()>: ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Attack, &target);
		return ;
	}
	_mana--;
	_printAction(Attack, _damage, &target);
}

// public methods:
void	ScavTrap::guardGate() {
	std::cout << "<" << _className << " method guardGate()>: ";
	std::cout << *this << " is now in gate keeper mode." << std::endl;
}

#include "FragTrap.hpp"
#include <iostream>

const std::string	FragTrap::_className = "Fragtrap";
const int			FragTrap::_defaultHp = 100;
const int			FragTrap::_defaultMana = 100;
const int			FragTrap::_defaultDamage = 30;


std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject) {
	outStream << YELLOW_COLOR << fragTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

FragTrap::FragTrap()
	: ClapTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
	_initialize(_className + "_Default");
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name) {
		std::cout << _className << ": String constructor called" << std::endl;
	_initialize(name);
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public methods:
std::string	FragTrap::getClassName() const {
	return (_className);
}

std::string FragTrap::getName() const {
	return (_name);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "<" << _className << " method highFivesGuys()>: ";
	std::cout << *this << " wants to High Five you. Can we get a whoop whoop? (Positivity level is over 9000!!)" << std::endl;
}

// private methods:
void	FragTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = _defaultHp;
	_mana = _defaultMana;
	_damage = _defaultDamage;
}

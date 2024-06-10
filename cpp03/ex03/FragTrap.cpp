#include "FragTrap.hpp"
#include <iostream>

const std::string FragTrap::_className = "Fragtrap";

std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject) {
	outStream << YELLOW_COLOR << fragTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

FragTrap::FragTrap()
	: ClapTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
	_name = FRAG_DEFAULT_NAME;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name) {
		std::cout << _className << ": String constructor called" << std::endl;
	_name = name;
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

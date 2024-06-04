#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

const std::string FragTrap::_className = "Fragtrap";

std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject) {
	outStream << YELLOW_COLOR << fragTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

FragTrap::FragTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
		_initialize(FRAG_DEFAULT_NAME);
}

FragTrap::FragTrap(const std::string& name) {
		std::cout << _className << ": String constructor called" << std::endl;
		_initialize(name);
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// private methods:
void	FragTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = FRAG_DEFAULT_HP;
	_mana = FRAG_DEFAULT_MANA;
	_damage = FRAG_DEFAULT_DAMAGE;
}

// public Getters:
std::string	FragTrap::getClassName() const {
	return (_className);
}

std::string FragTrap::getName() const {
	return (_name);
}

// public methods:
void	FragTrap::highFivesGuys(void) {
	std::cout << "<" << _className << " method highFivesGuys()>: ";
	std::cout << *this << " wants to High Five you. Can we get a whoop whoop? (Positivity level is over 9000)" << std::endl;
}

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

const std::string	ClapTrap::_className = "Claptrap";
const int			ClapTrap::_defaultHp = 10;
const int			ClapTrap::_defaultMana = 10;
const int			ClapTrap::_defaultDamage = 0;

std::ostream& operator<<(std::ostream& outStream, const ClapTrap& clapTrapObject) {
	outStream << YELLOW_COLOR << clapTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

ClapTrap::ClapTrap()
	: _name(_className + "_Default"), _hp(_defaultHp), _mana(_defaultMana), _damage(_defaultDamage) {
	std::cout << _className << ": Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hp(_defaultHp),	_mana(_defaultMana), _damage(_defaultDamage) {
	std::cout << _className << ": String constructor called" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << _className << ": Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public methods:
std::string	ClapTrap::getClassName() const {
	return (_className);
}

std::string ClapTrap::getName() const {
	return (_name);
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << _className << " method attack(): ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Attack, &target);
		return ;
	}
	_mana--;
	_printAction(Attack, _damage, &target);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _className << " method takeDamage(): ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Tank);
		return ;
	}
	_hp -= amount;
	_printAction(Tank, amount);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _className << " method beRepaired(): ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Heal);
		return ;
	}
	_hp += amount;
	_mana--;
	_printAction(Heal, amount);
}

void	ClapTrap::printStatus() const {
	std::cout << _className << " " << *this << ": ";
	_printHpAndMana();
	std::cout << std::endl;
}

// private methods:
void	ClapTrap::_printHpAndMana() const{
	std::cout << RED_COLOR << _hp << " HP" << RESET_COLOR << " and "
		<< BLUE_COLOR << _mana << " Mana " << RESET_COLOR << "left.";
}

void	ClapTrap::_printAction(ActionType aType, unsigned int amount, const std::string* target) const {
	std::cout << *this << " ";
	switch (aType) {
		case Attack:
			std::cout << CYAN_COLOR << "attacks " << YELLOW_COLOR << *target << " with "
				<< _damage << " damage";
			break;
		case Tank:
			std::cout << MAGENTA_COLOR << "is taking " << amount << " damage";
			break;
		case Heal:
			std::cout << GREEN_COLOR << "is healing for " << amount << " HP";
			break;
		default:
			std::cout << "performs unknown action";
	}
	std::cout << RESET_COLOR << " -> ";
	_printHpAndMana();
	std::cout  << std::endl;
}

void	ClapTrap::_printFailure(ActionType aType, const std::string* target) const {
	std::cout << *this << " ";
	switch (aType) {
		case Attack:
			std::cout << GREY_COLOR << "cannot attack " << YELLOW_COLOR << *target;
			break;
		case Tank:
			std::cout << GREY_COLOR << "cannot take damage";
			break;
		case Heal:
			std::cout << GREY_COLOR << "cannot heal";
			break;
		default:
			std::cout << "do anything";
	}
	std::cout << RESET_COLOR << " -> ";
	_printHpAndMana();
	std::cout << std::endl;
}

bool	ClapTrap::_hasEnoughHpAndMana() const {
	return (_hp > 0 && _mana > 0);
}

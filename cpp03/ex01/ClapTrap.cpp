#include "ClapTrap.hpp"
#include <iostream>
#include <string>

const std::string ClapTrap::_className = "Claptrap";

std::ostream& operator<<(std::ostream& outStream, const ClapTrap& clapTrapObject) {
	outStream << YELLOW_COLOR << clapTrapObject.getName() << RESET_COLOR;
	return (outStream);
}

void	ClapTrap::_initialize(const std::string& name) {
	_name = name;
	_hp = CLAP_DEFAULT_HP;
	_mana = CLAP_DEFAULT_MANA;
	_damage = CLAP_DEFAULT_DAMAGE;
}

ClapTrap::ClapTrap() {
		std::cout << _className << ": Default constructor called" << std::endl;
		_initialize(CLAP_DEFAULT_NAME);
}

ClapTrap::ClapTrap(const std::string& name) {
		std::cout << _className << ": String constructor called" << std::endl;
		_initialize(name);
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _hp(other._hp), _mana(other._mana), _damage(other._damage){
	std::cout << _className << ": Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << _className << ": Copy assignment operator called" << std::endl;
	if (this != &other) {
		_hp = other._hp;
		_mana = other._mana;
		_damage = other._damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// public Getters:
std::string	ClapTrap::getClassName() const {
	return (_className);
}

std::string ClapTrap::getName() const {
	return (_name);
}

// private methods:
void	ClapTrap::_printHpAndMana() {
	std::cout << RED_COLOR << _hp << " HP" << RESET_COLOR << " and "
		<< BLUE_COLOR << _mana << " Mana " << RESET_COLOR << "left.";
}

void	ClapTrap::_printAction(ActionType aType, unsigned int amount, const std::string* target) {
	std::cout << *this << " ";
	switch (aType) {
		case Attack:
			std::cout << CYAN_COLOR << "attacks " << YELLOW_COLOR << *target;
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

void	ClapTrap::_printFailure(ActionType aType, const std::string* target) {
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

bool	ClapTrap::_hasEnoughHpAndMana() {
	return (_hp > 0 && _mana > 0);
}

// public methods:
void	ClapTrap::attack(const std::string& target) {
	std::cout << "<" << _className << " method attack()>: ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Attack, &target);
		return ;
	}
	_mana--;
	_printAction(Attack, _damage, &target);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "<" << _className << " method takeDamage()>: ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Tank);
		return ;
	}
	_hp -= amount;
	_printAction(Tank, amount);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "<" << _className << " method beRepaired()>: ";
	if (!_hasEnoughHpAndMana()) {
		_printFailure(Heal);
		return ;
	}
	_hp += amount;
	_mana--;
	_printAction(Heal, amount);
}
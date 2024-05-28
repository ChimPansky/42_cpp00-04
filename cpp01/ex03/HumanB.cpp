#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) :
	_name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon == NULL)
		std::cout << "bare hands";
	else
		std::cout << this->_weapon->getType();
	std::cout << std::endl;
}

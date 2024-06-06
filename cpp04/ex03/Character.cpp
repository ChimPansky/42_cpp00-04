#include "Character.hpp"
#include <iostream>

Character::Character() {}

Character::Character(std::string name)
	: _name(name) {}

Character::~Character() {}

std::string const & Character::getName() const{
	return _name;
}

void				Character::equip(AMateria* m) {
	if (m == 0) {
		std::cerr << "cannot equip empty AMateria!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_materiaInventory[i] == 0) {
			_materiaInventory[i] = m;
			std::cout << "Ability successfully equiped in slot " << i << "!" << std::endl;
			return;
		}
	}
	std::cerr << "Inventory full! Cannot equip ability." << std::endl;
}

void				Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cerr << "Character::unequip(): Index out of range: " << idx << std::endl;
		return ;
	}
	if (_materiaInventory[idx] == 0) {
		std::cerr << "Character::unequip(): Cannot unequip empty slot " << idx << std::endl;
		return ;
	}
	_materiaInventory[idx] = 0;
	std::cout << "Character::unequip(): Successfully unequipped slot " << idx << std::endl;
	// how to not delete the Matera and avoid leaks at the same time??
}
void				Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cerr << "Character::use(): Index out of range: " << idx << std::endl;
		return ;
	}
	if (_materiaInventory[idx] == 0) {
		std::cerr << "Character::use(): Cannot use ability (Slot " << idx << " empty)" << std::endl;
		return ;
	}
	_materiaInventory[idx]->use(target);
}

void	Character::printInventory() const {
	for (int i = 0; i < 4; i++) {
		std::cout << "MateriaSource[" << i << "]: ";
		if (_materiaInventory[i] == 0)
			std::cout << "{empty slot}" << std::endl;
		else
			std::cout << _materiaInventory[i]->getType() << std::endl;
	}
}

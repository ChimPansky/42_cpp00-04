#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

List			Character::_droppedMaterias;
MateriaCleaner	Character::_materiaCleaner(&_droppedMaterias);

Character::Character() {
	CHARACTER_VERBOSE_OUT("Character:: Constructor() called");
	for (int i= 0; i < 4; i++) {
		_materiaInventory[i] = 0;
	}
}

Character::Character(std::string name)
	: _name(name) {
	CHARACTER_VERBOSE_OUT("Character:: Constructor(name) called");
	for (int i= 0; i < 4; i++) {
		_materiaInventory[i] = 0;
	}
}

Character::Character(const Character& other) {
	CHARACTER_VERBOSE_OUT("Character:: Copy Constructor called");
	for (int i= 0; i < 4; i++) {
		_materiaInventory[i] = 0;
	}
	*this = other;
}

Character& Character::operator=(const Character& other) {
	CHARACTER_VERBOSE_OUT("Character:: Copy assignment operator overload called");
	if (this != &other) {
		_name = other._name;
		_deleteInventory();	// deletes all slots and sets them to 0
		_cloneInventory(other);	// makes copies of other's slots and equips them
	}
	return *this;
}

Character::~Character() {
	CHARACTER_VERBOSE_OUT("Character:: " << _name << " Destructor called");
	_deleteInventory();
}

std::string const & Character::getName() const{
	return _name;
}

void	Character::setName(const std::string& name) {
	_name = name;;
}

void				Character::equip(AMateria* m) {
	if (m == 0) {
		std::cerr << "cannot equip empty AMateria!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_materiaInventory[i] == 0) {
			_materiaInventory[i] = m;
			std::cout << "Ability successfully equipped in slot " << i << "!" << std::endl;
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
	_materiaCleaner.addMateria(_materiaInventory[idx]);
	_materiaInventory[idx] = 0;
	std::cout << "Character::unequip(): Successfully unequipped slot " << idx << std::endl;
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
	CHARACTER_VERBOSE_OUT("Character::printInventory() called");
	std::cout << _name << "'s inventory:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "Inventory[" << i << "]: ";
		if (_materiaInventory[i] == 0)
			std::cout << "{empty slot}" << std::endl;
		else
			std::cout << _materiaInventory[i]->getType() << "(ptr: "
				<< _materiaInventory[i] << ")" << std::endl;
	}
}

void	Character::_deleteInventory() {
	CHARACTER_VERBOSE_OUT("Character::deleteInventory() called");
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (_materiaInventory[i] == 0)
				continue;
			if (_materiaInventory[i] == _materiaInventory[j])
				_materiaInventory[j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (_materiaInventory[i] != 0) {
			CHARACTER_VERBOSE_OUT("Character::deleteInventory(): deleting Materia "
				<< _materiaInventory[i])
			delete _materiaInventory[i];
			_droppedMaterias.remove(_materiaInventory[i]);
			_materiaInventory[i] = 0;
		}
	}
};

void	Character::_cloneInventory(const Character& other) {
	CHARACTER_VERBOSE_OUT("Character::cloneInventory called");
	for (int i = 0; i < 4; i++) {
		if (other._materiaInventory[i] != 0)
			_materiaInventory[i] = other._materiaInventory[i]->clone();
	}
}

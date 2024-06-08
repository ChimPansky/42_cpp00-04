#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i= 0; i < 4; i++) {
		_learnedMaterias[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i= 0; i < 4; i++) {
		_learnedMaterias[i] = 0;
	}
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		_deleteMaterias();
		_cloneMaterias(other);
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	_deleteMaterias();
}

void	MateriaSource::learnMateria(AMateria* materia) {
	//append to _learnedMaterias...
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterias[i] == 0) {
			_learnedMaterias[i] = materia;
			return ;
		}
	}
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterias[i] != 0 && _learnedMaterias[i]->getType() == type) {
			return (_learnedMaterias[i]->clone());
		}
	}
	return 0;
}

void	MateriaSource::printMaterias() const {
	for (int i = 0; i < 4; i++) {
		std::cout << "MateriaSource[" << i << "]: ";
		if (_learnedMaterias[i] == 0)
			std::cout << "{empty slot}" << std::endl;
		else
			std::cout << _learnedMaterias[i]->getType() << std::endl;
	}
}

void	MateriaSource::_deleteMaterias() {
	// check if there are duplicate pointers to avoid double deletes...
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterias[i] != 0) {
			delete _learnedMaterias[i];
			_learnedMaterias[i] = 0;
		}
	}
}

void	MateriaSource::_cloneMaterias(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._learnedMaterias[i] != 0)
			_learnedMaterias[i] = other._learnedMaterias[i]->clone();
	}
}

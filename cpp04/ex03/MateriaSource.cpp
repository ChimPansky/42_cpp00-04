#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	MATERIASOURCE_VERBOSE_OUT("Materiasource:: Constructor() called");
	for (int i= 0; i < 4; i++) {
		_learnedMaterias[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	MATERIASOURCE_VERBOSE_OUT("Materiasource:: Copy Constructor called");
	for (int i= 0; i < 4; i++) {
		_learnedMaterias[i] = 0;
	}
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	MATERIASOURCE_VERBOSE_OUT("Materiasource:: Copy assignment operator overload called");
	if (this != &other) {
		_deleteMaterias();
		_cloneMaterias(other);
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	MATERIASOURCE_VERBOSE_OUT("Materiasource:: Destruct called");
	_deleteMaterias();
}

void	MateriaSource::learnMateria(AMateria* materia) {
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
	MATERIASOURCE_VERBOSE_OUT("Materiasource::printInventory() called");
	std::cout << this << "'s learned Materias:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "MateriaSource[" << i << "]: ";
		if (_learnedMaterias[i] == 0)
			std::cout << "{empty slot}" << std::endl;
		else
			std::cout << _learnedMaterias[i]->getType() << std::endl;
	}
}

void	MateriaSource::_deleteMaterias() {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (_learnedMaterias[i] == 0)
				continue;
			if (_learnedMaterias[i] == _learnedMaterias[j])
				_learnedMaterias[j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterias[i] != 0) {
			MATERIASOURCE_VERBOSE_OUT("MateriaSource::deleteMaterias(): deleting Materia "
				<< _learnedMaterias[i])
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

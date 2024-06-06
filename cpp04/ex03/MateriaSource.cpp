#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() {}

void	MateriaSource::learnMateria(AMateria* materia) {
	//append to _learnedMaterias...
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterias[i] == 0) {
			_learnedMaterias[i] = materia;
			break;
		}
	}
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

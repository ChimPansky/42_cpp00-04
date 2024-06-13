#include "MateriaCleaner.hpp"
#include <iostream>
#include "../AMateria.hpp"

MateriaCleaner::MateriaCleaner(List* droppedMaterias) {
	MATERIACLEANER_VERBOSE_OUT("Materiacleaner:: Constructor() called");
	_droppedMaterias = droppedMaterias;
}

MateriaCleaner::~MateriaCleaner() {
	MATERIACLEANER_VERBOSE_OUT("Materiacleaner:: Destructor called");
	_cleanMaterias();
}

void	MateriaCleaner::addMateria(AMateria *m) {
	_droppedMaterias->append((void*)m);
}

void	MateriaCleaner::_cleanMaterias() {
	MATERIACLEANER_VERBOSE_OUT("MateriaCleaner::_cleanMateria():")
	void*	toDelete = 0;
	if (MATERIACLEANER_VERBOSE)
		_droppedMaterias->print();
	while (!_droppedMaterias->isEmpty()) {
		toDelete = _droppedMaterias->getVal(_droppedMaterias->getHead());
		MATERIACLEANER_VERBOSE_OUT("deleting Materia: " << toDelete)
		delete (AMateria*)toDelete;
		_droppedMaterias->remove(toDelete);
	}
}

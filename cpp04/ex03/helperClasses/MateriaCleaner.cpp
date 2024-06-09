#include "MateriaCleaner.hpp"
#include <iostream>

List	MateriaCleaner::_droppedMaterias;

MateriaCleaner::~MateriaCleaner() {
	std::cout << "MateriaCleaner Destructor: deleting unequipped Materias..." << std::endl;
	Character::cleanMaterias();
	void*	toDelete = 0;
	while (!_droppedMaterias.isEmpty()) {
		toDelete = _droppedMaterias.getVal(_droppedMaterias.getHead());
		std::cout << "deleting Materia: " << toDelete << std::endl;
		delete (AMateria*)toDelete;
		_droppedMaterias.remove(toDelete);
	}
}

void	MateriaCleaner::addMateria(AMateria *m) {
	_droppedMaterias.append((void*)m);
}

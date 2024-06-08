#include "MateriaCleaner.hpp"
#include <iostream>

List	MateriaCleaner::_droppedMaterias;

MateriaCleaner::~MateriaCleaner() {
	std::cout << "MateriaCleaner Destructor: listDeleteAll..." << std::endl;
	_droppedMaterias.listDeleteAll();
}

void	MateriaCleaner::addMateria(AMateria *m) {
	_droppedMaterias.lAppend((void*)m);
}

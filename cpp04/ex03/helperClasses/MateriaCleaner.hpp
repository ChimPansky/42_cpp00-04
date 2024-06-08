#pragma once
#include "List.hpp"
#include "../AMateria.hpp"

class MateriaCleaner {
  private:
	static List	_droppedMaterias;

  public:
	~MateriaCleaner();

	void addMateria(AMateria* m);
};

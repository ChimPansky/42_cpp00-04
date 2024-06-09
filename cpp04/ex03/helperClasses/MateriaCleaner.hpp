#pragma once
#include "List.hpp"
#include "../AMateria.hpp"

class MateriaCleaner {
  public:
	~MateriaCleaner();

	void addMateria(AMateria* m);
};

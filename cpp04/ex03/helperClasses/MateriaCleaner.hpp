#pragma once
#include "List.hpp"

#define MATERIACLEANER_VERBOSE 0
#if MATERIACLEANER_VERBOSE
# define MATERIACLEANER_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define MATERIACLEANER_VERBOSE_OUT(msg)
#endif

class AMateria;

class MateriaCleaner {
  public:
  	MateriaCleaner(List* droppedMaterias);
	~MateriaCleaner();

	void	addMateria(AMateria* m);

  private:
	void	_cleanMaterias();
	List*	_droppedMaterias;
};

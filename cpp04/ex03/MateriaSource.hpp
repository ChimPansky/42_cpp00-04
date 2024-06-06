#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {
  public:
	MateriaSource();
	~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

	void		printMaterias() const;

  private:
	AMateria*	_learnedMaterias[4]; // this contains any combination of ice* and cure* or NULL if empty slot
};

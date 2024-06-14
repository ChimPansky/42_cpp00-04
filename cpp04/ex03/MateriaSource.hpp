#include "IMateriaSource.hpp"

#define MATERIASOURCE_VERBOSE 1
#if MATERIASOURCE_VERBOSE
# define MATERIASOURCE_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define MATERIASOURCE_VERBOSE_OUT(msg)
#endif

class MateriaSource : public IMateriaSource {
  public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

	void		printMaterias() const;

  private:
	AMateria*	_learnedMaterias[4]; // this contains any combination of ice* and cure* or NULL if empty slot
	void		_deleteMaterias();
	void		_cloneMaterias(const MateriaSource& other);
};

#pragma once

#include <string>

#define AMATERIA_VERBOSE 0
#if AMATERIA_VERBOSE
# define AMATERIA_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define AMATERIA_VERBOSE_OUT(msg)
#endif

class ICharacter;

class	AMateria {
  protected:
	std::string	_type;

  public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#pragma once
#include "AMateria.hpp"

#define CURE_VERBOSE 0
#if CURE_VERBOSE
# define CURE_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define CURE_VERBOSE_OUT(msg)
#endif

class Cure : public AMateria {
  public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	std::string const&	getType() const;
	AMateria*			clone() const;
	void				use(ICharacter& target);
};

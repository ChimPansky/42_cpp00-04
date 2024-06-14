#pragma once
#include "AMateria.hpp"

#define ICE_VERBOSE 0
#if ICE_VERBOSE
# define ICE_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define ICE_VERBOSE_OUT(msg)
#endif

class Ice : public AMateria {
  public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	std::string const&	getType() const;
	AMateria*			clone() const;
	void				use(ICharacter& target);
};

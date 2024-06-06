#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {
  public:
	Cure();
	Cure(const Cure& other);
	~Cure();

	std::string const&	getType() const;
	AMateria*			clone() const;
	void				use(ICharacter& target);
};

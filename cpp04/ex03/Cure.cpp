#include "Cure.hpp"
#include <iostream>

Cure::Cure()
	:	AMateria("cure") {}

Cure::Cure(const Cure& other)
	:	AMateria("cure") {
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	(void) other;
	return *this;
}

Cure::~Cure() {}

std::string const& Cure::getType() const {
	return _type;
}

AMateria*			Cure::clone() const {
	return (new Cure(*this));
}

void				Cure::use(ICharacter& target) {
	(void) target;
	std::cout << "* heals " << /*target.getName()*/ "unknown" << "’s wounds *" << std::endl;
}

#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure()
	:	AMateria("cure") {
	CURE_VERBOSE_OUT("Cure:: Constructor() called");
}

Cure::Cure(const Cure& other)
	:	AMateria("cure") {
	CURE_VERBOSE_OUT("Cure:: Copy Constructor called");
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	CURE_VERBOSE_OUT("Cure:: Copy assignment operator overload called");
	(void) other;
	return *this;
}

Cure::~Cure() {
	CURE_VERBOSE_OUT("Cure:: Destructor called");
}

std::string const& Cure::getType() const {
	return _type;
}

AMateria*			Cure::clone() const {
	return (new Cure(*this));
}

void				Cure::use(ICharacter& target) {
	(void) target;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

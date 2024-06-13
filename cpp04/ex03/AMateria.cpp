#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
	: _type("Default") {
		AMATERIA_VERBOSE_OUT("Amateria:: Constructor() called");
	}

AMateria::AMateria(std::string const & type)
	: _type(type) {
		AMATERIA_VERBOSE_OUT("Amateria:: Constructor(type) called");
	}

AMateria::AMateria(const AMateria& other) {
	AMATERIA_VERBOSE_OUT("Amateria:: Copy Constructor called");
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	AMATERIA_VERBOSE_OUT("Amateria:: Copy assignment operator overload called");
	if (this == &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	AMATERIA_VERBOSE_OUT("Amateria:: Destructor called");
}

std::string const & AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	(void) target;
	std::cout << "using abstract AMateria (this can never happen...)" << std::endl;
}

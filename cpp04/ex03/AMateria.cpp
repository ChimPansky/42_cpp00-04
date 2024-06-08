#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
	: _type("Default") {}

AMateria::AMateria(std::string const & type)
	: _type(type) {}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this == &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	(void) target;
	std::cout << "using abstract AMateria..." << std::endl;
}

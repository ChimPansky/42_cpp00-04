#include "Ice.hpp"
#include <iostream>

Ice::Ice()
	:	AMateria("ice") {}

Ice::Ice(const Ice& other)
	:	AMateria("ice") {}

Ice::~Ice() {}

std::string const& Ice::getType() const {
	return _type;
}

AMateria*			Ice::clone() const {
	return (new Ice(*this));
}

void				Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << /*target.getName()*/ "unknown" << " *" << std::endl;
}

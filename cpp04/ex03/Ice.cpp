#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice()
	:	AMateria("ice") {
	ICE_VERBOSE_OUT("Ice:: Constructor() called");
}

Ice::Ice(const Ice& other)
	:	AMateria("ice") {
	ICE_VERBOSE_OUT("Ice:: Copy Constructor called");
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	ICE_VERBOSE_OUT("Ice:: Copy assignment operator overload called");
	(void) other;
	return *this;
}

Ice::~Ice() {
	ICE_VERBOSE_OUT("Ice:: Destructor called");
}

std::string const& Ice::getType() const {
	return _type;
}

AMateria*			Ice::clone() const {
	return (new Ice(*this));
}

void				Ice::use(ICharacter& target) {
	(void) target;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

#include "Brain.hpp"
#include <iostream>

const std::string Brain::_className = "Brain";

Brain::Brain() {
	std::cout << _className << ": Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	for (int i = 0; i < brainIdeaCount; i++) {
		_ideas[i] = other._ideas[i];
	}
}

std::string* Brain::getIdeas() {
	return _ideas;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << _className << ": Copy assignment operator overload called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < brainIdeaCount; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << _className << ": Destructor called" << std::endl;
}

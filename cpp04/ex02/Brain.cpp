#include "Brain.hpp"
#include <iostream>

const std::string	Brain::_className = "Brain";
const std::string	Brain::_invalidIndexString = "Invalid Index!";

Brain::Brain() {
	std::cout << _className << ": Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	*this = other;
}

const std::string&	Brain::getIdea(int idx) const {
	if (idx < 0 || idx >= brainIdeaCount ) {
		std::cerr << "Brain::getIdea: Index out of bounds (" << brainIdeaCount << ")" << std::endl;
		return _invalidIndexString;
	}
	return (_ideas[idx]);
}

void	Brain::setIdea(int idx, const std::string& idea) {
	if (idx < 0 || idx >= brainIdeaCount ) {
		std::cerr << _invalidIndexString << std::endl;
		return ;
	}
	_ideas[idx] = idea;
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

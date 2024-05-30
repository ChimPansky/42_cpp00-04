#include "Climber.hpp"

Climber::Climber(const std::string &name)
    : _name(name), _ascents(NULL) {};

Climber::Climber(const Climber& other) {
	if (this != &other) {
		_name = other._name;
		_ascents = NULL;
	}
}

Climber& Climber::operator=(const Climber& other) {
	if (this != &other) {
		_name = other._name;
		_ascents = NULL;
	}
	return *this;
}

Climber::~Climber() {
	delete _ascents;
}

#pragma once

#include "Animal.hpp"
#include <string>

#define DOG_DEFAULT_TYPE	"Dog"

class Dog: public Animal {
  public:
	Dog();
	Dog(const std::string& type);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

  protected:
	std::string	_type;

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

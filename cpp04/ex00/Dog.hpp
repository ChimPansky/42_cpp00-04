#pragma once

#include "Animal.hpp"
#include <string>

class Dog: public Animal {
  public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void	makeSound() const;

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

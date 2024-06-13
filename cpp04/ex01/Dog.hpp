#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog: public Animal {
  public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void	makeSound() const;
	Brain*	getBrain();

  private:
	static const std::string	_className;
	static const std::string	_sound;
	Brain*						_brain;

	void	_initialize(const std::string& type);
};

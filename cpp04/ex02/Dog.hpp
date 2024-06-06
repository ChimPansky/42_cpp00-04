#pragma once

#include "IAnimal.hpp"
#include "Brain.hpp"
#include <string>

#define DOG_DEFAULT_TYPE	"Dog"

class Dog: public IAnimal {
  public:
	Dog();
	Dog(const std::string& type);
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

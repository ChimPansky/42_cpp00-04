#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

#define CAT_DEFAULT_TYPE	"Cat"

class Cat: public Animal {
  public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void	makeSound() const;
	Brain*	getBrain();

  private:
	static const std::string	_className;
	static const std::string	_sound;
	Brain*						_brain;

	void	_initialize(const std::string& type);
};

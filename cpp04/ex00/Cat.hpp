#pragma once

#include "Animal.hpp"
#include <string>

class Cat: public Animal {
  public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void	makeSound() const;

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

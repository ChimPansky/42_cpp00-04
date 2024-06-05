#pragma once

#include "Animal.hpp"
#include <string>

#define CAT_DEFAULT_TYPE	"Cat"

class Cat: public Animal {
  public:
	Cat();
	Cat(const std::string& type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	virtual void	makeSound() const;

  protected:
	std::string	_type;

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

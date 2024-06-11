#pragma once

#include "WrongAnimal.hpp"
#include <string>

#define WRONG_CAT_DEFAULT_TYPE	"Wrong Cat"

class WrongCat: public WrongAnimal {
  public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();

	void	makeSound() const;

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

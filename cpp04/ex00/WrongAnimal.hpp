#pragma once

#include <string>
#define WRONG_ANIMAL_DEFAULT_TYPE	"Unkown Wrong Animal"

class WrongAnimal {
  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	// Getters:
	std::string	getType() const;

	// public methods:
	void	makeSound() const;

  protected:
  	std::string	_type;
	void	_initialize(const std::string& type);

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

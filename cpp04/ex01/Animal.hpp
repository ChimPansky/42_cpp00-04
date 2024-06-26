#pragma once

#include <string>
#define ANIMAL_DEFAULT_TYPE	"Unknown Animal"

class Animal {
  public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	// Getters:
	std::string	getType() const;

	// public methods:
	virtual void	makeSound() const;

  protected:
	std::string	_type;
	void	_initialize(const std::string& type);

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

#pragma once

#include <string>

class IAnimal {
  public:
	IAnimal();
	IAnimal(const std::string& type);
	IAnimal(const IAnimal& other);
	IAnimal& operator=(const IAnimal& other);
	virtual ~IAnimal();

	// Getters:
	std::string	getType() const;

	// public methods:
	virtual void	makeSound() const = 0;

  protected:
	std::string	_type;
	virtual void	_initialize(const std::string& type = "void");

  private:
	static const std::string	_className;
	static const std::string	_sound;
};

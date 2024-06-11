#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap{
  public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	// Getters:
	std::string	getClassName() const;
	std::string	getName() const;

	void		whoAmI();

  private:
	std::string					_name;
	void		_initialize(const std::string& name);

	//statics:
	static const std::string	_className;
};

std::ostream& operator<<(std::ostream& outStream, const DiamondTrap& scavTrapObject);

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#define DIAMOND_DEFAULT_NAME	"DUnknown"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap{
  private:
	std::string					_name;
	static const std::string	_className;

	void	_initialize(const std::string& name);

  public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	// Getters:
	std::string	getClassName() const;
	std::string	getName() const;

	void	whoAmI();
};

std::ostream& operator<<(std::ostream& outStream, const DiamondTrap& scavTrapObject);

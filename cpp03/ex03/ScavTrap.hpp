#pragma once

#include "ClapTrap.hpp"
#include <string>
#define SCAV_DEFAULT_NAME	"SUnknown"
#define SCAV_DEFAULT_HP		100
#define SCAV_DEFAULT_MANA	50
#define SCAV_DEFAULT_DAMAGE	20

class ScavTrap : virtual public ClapTrap{
  private:
	static const std::string	_className;
	void	_initialize(const std::string& name);

  public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	// Getters:
	std::string	getClassName() const;
	std::string	getName() const;

	void	attack(const std::string& target);
	void	guardGate();
};

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject);

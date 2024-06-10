#pragma once

#include "ClapTrap.hpp"
#include <string>
#define SCAV_DEFAULT_NAME	"ScavTrap Unknown"
#define SCAV_DEFAULT_HP		100
#define SCAV_DEFAULT_MANA	50
#define SCAV_DEFAULT_DAMAGE	20

class ScavTrap : public ClapTrap{
  public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	// public methods
	std::string	getClassName() const;
	std::string	getName() const;

	void		attack(const std::string& target);
	void		guardGate();

  private:
	static const std::string	_className;
};

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject);

#pragma once

#include "ClapTrap.hpp"
#include <string>

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
	void		_initialize(const std::string& name);
	// statics:
	static const std::string	_className;
	static const int			_defaultHp;
	static const int			_defaultMana;
	static const int			_defaultDamage;
};

std::ostream& operator<<(std::ostream& outStream, const ScavTrap& scavTrapObject);

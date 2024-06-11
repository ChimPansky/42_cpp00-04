#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap{
  public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	virtual ~FragTrap();

	// public methods
	std::string	getClassName() const;
	std::string	getName() const;

	void		highFivesGuys(void);

  private:
	void		_initialize(const std::string& name);

  protected:
	// statics:
	static const std::string	_className;
	static const int			_defaultHp;
	static const int			_defaultMana;
	static const int			_defaultDamage;
};

std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject);

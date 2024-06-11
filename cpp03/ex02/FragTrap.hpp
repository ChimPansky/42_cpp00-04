#pragma once

#include "ClapTrap.hpp"
#include <string>

#define FRAG_DEFAULT_NAME	"FragTrap Unknown"
#define FRAG_DEFAULT_HP		100
#define FRAG_DEFAULT_MANA	100
#define FRAG_DEFAULT_DAMAGE	30

class FragTrap : public ClapTrap{
  public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	// public methods
	std::string	getClassName() const;
	std::string	getName() const;

	void		highFivesGuys(void);

  private:
	void		_initialize(const std::string& name);
	// statics:
	static const std::string	_className;
	static const int			_defaultHp;
	static const int			_defaultMana;
	static const int			_defaultDamage;
};

std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject);

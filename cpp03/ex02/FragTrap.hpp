#pragma once

#include "ClapTrap.hpp"
#include <string>

#define FRAG_DEFAULT_NAME	"Unknown"
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

	void	highFivesGuys(void);

  private:
	static const std::string	_className;
	void	_initialize(const std::string& name);
};

std::ostream& operator<<(std::ostream& outStream, const FragTrap& fragTrapObject);

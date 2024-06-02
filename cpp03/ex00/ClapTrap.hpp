#pragma once

#include <string>

class ClapTrap {
  public:
	enum Message {
		Attack = 1,
		TakeDamage = 2,
		BeRepaired = 3,
		NoHealth = 4,
		NoEnergy = 5
	};

  private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	static const std::string	_className;
	void		_printMessage(Message message, const std::string& target, unsigned int amount);
	bool		_isInactive();

  public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

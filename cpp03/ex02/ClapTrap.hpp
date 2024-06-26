#pragma once

#include <string>

const std::string RESET_COLOR = "\033[0m";
const std::string RED_COLOR = "\033[31m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";
const std::string BLUE_COLOR = "\033[34m";
const std::string MAGENTA_COLOR = "\033[35m";
const std::string CYAN_COLOR = "\033[36m";
const std::string GREY_COLOR = "\033[90m";

class ClapTrap {
  public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	enum ActionType {
		Attack = 1,
		Tank = 2,
		Heal = 3,
	};

	// public methods:
	std::string	getClassName() const;
	std::string	getName() const;

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			printStatus() const;

  protected:
	std::string		_name;
	int				_hp;
	int				_mana;
	int				_damage;
	void			_printHpAndMana() const;
	void			_printAction(ActionType aType, unsigned int amount,
						const std::string* target = NULL) const;
	void			_printFailure(ActionType aType, const std::string* target = NULL) const;
	bool			_hasEnoughHpAndMana() const;

	// statics:
	static const std::string	_className;
	static const int			_defaultHp;
	static const int			_defaultMana;
	static const int			_defaultDamage;
};

std::ostream& operator<<(std::ostream& outStream, const ClapTrap& clapTrapObject);

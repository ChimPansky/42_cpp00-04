#pragma once

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter{
  public:
	Character();
	Character(std::string name);
	~Character();

	std::string const & getName() const;		// find out if i can omit this, since its declared in ICharacter... otherwise: whats the point of interface class??
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	void				printInventory() const;

  private:
	std::string	_name;
	AMateria*	_materiaInventory[4]; // this contains any combination of ice* and cure* or NULL if empty slot
};

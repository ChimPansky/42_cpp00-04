#pragma once

#define CHARACTER_VERBOSE 1
#if CHARACTER_VERBOSE
# define CHARACTER_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define CHARACTER_VERBOSE_OUT(msg)
#endif


#include "ICharacter.hpp"
#include <string>
#include "helperClasses/MateriaCleaner.hpp"

class Character : public ICharacter{
  public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const;		// find out if i can omit this, since its declared in ICharacter... otherwise: whats the point of interface class??
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	void				printInventory() const;

  private:
	std::string	_name;
	AMateria*	_materiaInventory[4]; // this contains any combination of ice* and cure* or NULL if empty slot
	void				_deleteInventory();
	void				_cloneInventory(const Character& other);


	static List				_droppedMaterias;
	static MateriaCleaner	_materiaCleaner;
};

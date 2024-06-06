
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main() {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->printMaterias();

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->printInventory();

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	me->equip(tmp);
	me->equip(tmp);
	me->unequip(2);
	me->unequip(5);
	me->unequip(0);
	me->unequip(0);
	me->printInventory();

	tmp = src->createMateria("ice");

	tmp = src->createMateria("iceeee");
	std::cout << "created_materia(ice): " << tmp << std::endl;


	// Ice	icy;
	// std::cout << "icy.getType(): " << icy.getType() << std::endl;

	return 0;
}


#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->printMaterias();
		AMateria* mat1 = new Ice();
		AMateria* mat2 = new Cure();
		src->learnMateria(mat1);
		src->learnMateria(mat1);
		src->learnMateria(mat2);
		src->learnMateria(mat2);
		src->printMaterias();

		std::cout << std::endl;

		ICharacter* C1 = new Character("Tweedledee");
		ICharacter* C2 = new Character("Tweedledum");
		AMateria* tmp;
		C1->printInventory();
		C2->printInventory();
		tmp = src->createMateria("ice");
		C1->equip(tmp);
		C1->equip(tmp);
		C1->equip(tmp);
		C1->equip(tmp);
		C1->equip(tmp);
		C1->printInventory();
		C1->use(0, *C2);
		tmp = src->createMateria("cure");
		C2->equip(tmp);
		C2->printInventory();
		C2->use(0, *C1);
		std::cout << std::endl;

		ICharacter* C3 = new Character;
		*C3 = *C2;
		C2->printInventory();
		C3->printInventory();

		delete src;
		delete C1;
		delete C2;
		delete C3;

	}
	std::cout << std::endl;
	{
		std::cout << "---SECTION 2 Tests from subject---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}


#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	{
		std::cout << "\n---SECTION 1---\n" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->printMaterias();
		AMateria* mat1 = new Ice();
		AMateria* mat2 = new Cure();
		src->learnMateria(mat1);
		src->learnMateria(mat1);
		src->learnMateria(mat2);
		src->learnMateria(mat2);
		src->printMaterias();

		std::cout << "\n---SECTION 2---\n" << std::endl;

		ICharacter* C1 = new Character("Tweedledee");
		ICharacter* C2 = new Character("Tweedledum");
		AMateria* tmp;
		C1->printInventory();
		C2->printInventory();

		std::cout << "\n---SECTION 3---\n" << std::endl;

		tmp = src->createMateria("ice");
		C1->equip(tmp);
		tmp = src->createMateria("cure");
		C1->equip(tmp);
		tmp = src->createMateria("ice");
		C1->equip(tmp);
		tmp = src->createMateria("cure");
		C1->equip(tmp);
		C2->equip(tmp);
		C1->equip(tmp);

		C1->printInventory();
		tmp = src->createMateria("cure");
		C2->equip(tmp);
		C2->printInventory();

		std::cout << "\n---SECTION 4---\n" << std::endl;

		C1->use(0, *C2);
		C2->use(0, *C1);

		std::cout << "\n---SECTION 5---\n" << std::endl;

		C1->unequip(0);
		C1->unequip(3);
		C1->printInventory();

		std::cout << "\n---SECTION 6---\n" << std::endl;

		ICharacter* C3 = new Character;
		// *C3 = *(Character*)C2;										// C-style casting
		*dynamic_cast<Character*>(C3) = *dynamic_cast<Character*>(C2);	// better use dynamic casting for downcasting Classes
		C3->setName(C3->getName() + "_clone");
		C2->printInventory();
		C3->printInventory();

		std::cout << "\n---SECTION 7---\n" << std::endl;

		Character* C4 = new Character(*dynamic_cast<Character*>(C3));
		C4->setName(C4->getName() + "_clone");
		C4->printInventory();

		std::cout << "\n---CLEANUP---\n" << std::endl;

		delete src;
		std::cout << std::endl;
		delete C1;
		std::cout << std::endl;
		delete C2;
		std::cout << std::endl;
		delete C3;
		std::cout << std::endl;
		delete C4;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\n---TESTS from subject---\n" << std::endl;
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

		std::cout << "\n---CLEANUP---\n" << std::endl;

		delete bob;
		delete me;
		delete src;
		return 0;
	}
}

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {
	{
		std::cout << "---SECTION 1: Animal Canonical Tests---" << std::endl;
		Animal* animal1 = new Animal;
		std::cout << std::endl;
		Animal* animal2 = new Animal(*animal1);
		std::cout << std::endl;
		Animal* animal3 = new Animal;
		*animal3 = *animal1;
		std::cout << std::endl;

		std::cout << "animal1.getType(): " << animal1->getType() <<  std::endl;
		animal1->makeSound();
		std::cout << "animal2.getType(): " << animal2->getType() <<  std::endl;
		animal2->makeSound();
		std::cout << "animal3.getType(): " << animal3->getType() <<  std::endl;
		animal3->makeSound();
		std::cout << std::endl;

		delete animal1;
		delete animal2;
		delete animal3;
		std::cout << std::endl;
	}
	{
		std::cout << "---SECTION 2: Dog Canonical Tests---" << std::endl;
		Animal* animal1 = new Dog;
		std::cout << std::endl;
		Dog* animal2 = new Dog;
		std::cout << std::endl;
		Dog* animal3 = new Dog(*animal2);
		std::cout << std::endl;
		*animal3 = *animal2;
		std::cout << std::endl;

		std::cout << "animal1.getType(): " << animal1->getType() <<  std::endl;
		animal1->makeSound();
		std::cout << "animal2.getType(): " << animal2->getType() <<  std::endl;
		animal2->makeSound();
		std::cout << "animal3.getType(): " << animal3->getType() <<  std::endl;
		animal3->makeSound();
		std::cout << std::endl;

		delete animal1;
		delete animal2;
		delete animal3;
		std::cout << std::endl;
	}
	{
		std::cout << "---SECTION 3: Cat Canonical Tests---" << std::endl;
		Animal* animal1 = new Cat;
		std::cout << std::endl;
		Cat* animal2 = new Cat;
		std::cout << std::endl;
		Cat* animal3 = new Cat(*animal2);
		std::cout << std::endl;
		*animal3 = *animal2;
		std::cout << std::endl;

		std::cout << "animal1.getType(): " << animal1->getType() <<  std::endl;
		animal1->makeSound();
		std::cout << "animal2.getType(): " << animal2->getType() <<  std::endl;
		animal2->makeSound();
		std::cout << "animal3.getType(): " << animal3->getType() <<  std::endl;
		animal3->makeSound();
		std::cout << std::endl;

		delete animal1;
		delete animal2;
		delete animal3;
		std::cout << std::endl;
	}
	{
		std::cout << "---SECTION 4: Tests from subject---" << std::endl;
		const Animal* animal1 = new Animal();
		std::cout << std::endl;
		const Animal* cat1 = new Cat();
		std::cout << std::endl;
		const Animal* dog1 = new Dog();

		std::cout << std::endl;

		std::cout << "animal getType(): " << animal1->getType() << " " << std::endl;
		std::cout << "cat getType(): " << cat1->getType() << " " << std::endl;
		std::cout << "dog getType(): " << dog1->getType() << " " << std::endl;

		std::cout << std::endl;

		animal1->makeSound();
		cat1->makeSound();
		dog1->makeSound();

		std::cout << std::endl;

		delete animal1;
		delete cat1;
		delete dog1;
	}

	std::cout << "\n---SECTION 4 Tests from subject for wrong class implementation---: \n" << std::endl;

	const WrongAnimal* wrongAnimal1 = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* wrongCat1 = new WrongCat();

	std::cout << std::endl;

	std::cout << "wrongAnimal getType(): " << wrongAnimal1->getType() << " " << std::endl;
	std::cout << "wrongCat getType(): " << wrongCat1->getType() << " " << std::endl;

	std::cout << std::endl;

	wrongAnimal1->makeSound();
	wrongCat1->makeSound();

	std::cout << std::endl;

	delete wrongAnimal1;
	delete wrongCat1;
}

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {
	const Animal* animal1 = new Animal();
	const Animal* cat1 = new Cat();
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

	std::cout << "\n---WrongAnimal and WrongCat tests: \n---" << std::endl;

	const WrongAnimal* wrongAnimal1 = new WrongAnimal();
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

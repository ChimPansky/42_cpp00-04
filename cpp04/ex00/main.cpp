#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main() {
	// Animal	a1;
	// Animal	a2("Fred");
	// Animal	a3(a2);
	// a2 = a3;

	// std::cout << "Animal 1 type: " << a1.getType() << std::endl;
	// std::cout << "Animal 2 type: " << a2.getType() << std::endl;
	// std::cout << "Animal 3 type: " << a3.getType() << std::endl;

	// Dog	dog1;
	// std::cout << "Dog 1 type: " << dog1.getType() << std::endl;
	// dog1.makeSound();

	// Cat	cat1;
	// std::cout << "Cag 1 type: " << cat1.getType() << std::endl;
	// cat1.makeSound();

	// return 0;

	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << "animal getType(): " << meta->getType() << " " << std::endl;
	std::cout << "cat getType(): " << i->getType() << " " << std::endl;
	std::cout << "dog getType(): " << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
}

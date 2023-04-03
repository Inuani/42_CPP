#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "Copy constructors:" << std::endl;

	const Animal* animalCopy = new Animal(*meta);
	const Cat*	catCopy = new Cat(*i);
	const Dog* dogCopy = new Dog(*j);

	std::cout << std::endl;
	std::cout << animalCopy->getType() << std::endl;
	std::cout << catCopy->getType() << std::endl;
	std::cout << dogCopy->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "Sounds of copied objects:" << std::endl;
	animalCopy->makeSound();
	catCopy->makeSound();
	dogCopy->makeSound();

	delete catCopy;
	delete dogCopy;
	delete animalCopy;

	std::cout << std::endl;
	std::cout << "Assignment operators:" << std::endl;

	Animal	animalAssi;
	Cat		catAssi;
	Dog		dogAssi;

	std::cout << std::endl;
	animalAssi = *meta;
	catAssi = *i;
	dogAssi = *j;

	std::cout << std::endl;
	std::cout << "Sounds of assigned objects:" << std::endl;
	animalAssi.makeSound();
	catAssi.makeSound();
	dogAssi.makeSound();

	std::cout << std::endl;
	delete i;
	delete j;
	delete meta;
	return 0;
}

// //Wrong main !
// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();

// 	std::cout << std::endl;
// 	const WrongAnimal* i = new WrongCat();

// 	std::cout << std::endl;
	

// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound();	// will output the cat sound!
// 	std::cout << std::endl;
// 	meta->makeSound();

// 	// ...
// 	std::cout << std::endl;
// 	delete i;
// 	delete meta;
// 	return 0;
// }

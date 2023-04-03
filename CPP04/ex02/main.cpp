#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const size_t	nbOfAnimals = 10;
	const size_t	half = nbOfAnimals / 2;

	const AAnimal* meta = new AAnimal();

	// AAnimal**	animalsArray = new AAnimal*[nbOfAnimals];

	for(size_t i = 0; i < nbOfAnimals; ++i)
	{
		if (i < half)
			animalsArray[i] = new Cat();
		else
			animalsArray[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << "Testing Brain private variable in the Cat and Dog objects in the array:" << std::endl;

	for(size_t i = 0; i < nbOfAnimals; i++)
	{
		const std::string* ideas = animalsArray[i]->getIdeas();
		std::cout << "Ideas of animal " << i << ":" << std::endl;
		for(size_t j = 0; j < 5; ++j)
			std::cout << "Idea " << j << ": " << ideas[j] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing deep copy:" << std::endl;

	Cat	minou;
	Cat minet(minou);

	std::string* changedIdea = minou.getIdeas();
	changedIdea[0] = "minou changed id_0";

	std::string* copiedOgIdea = minet.getIdeas();
		
	std::cout << "Original copied idea : " << copiedOgIdea[0] << std::endl;
	std::cout << "Changed initial idea : " << changedIdea[0] << std::endl;



	std::cout << std::endl;

	for(size_t i = 0; i < nbOfAnimals; ++i)
		delete animalsArray[i];
	delete[] animalsArray;

	return 0;
}


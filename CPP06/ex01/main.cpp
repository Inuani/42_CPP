#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data d;
	d.someData = 42;

	// Serialize the Data object
	uintptr_t serializedD = Serializer::serialize(&d);

	// Deserialize the uintptr_t value we got jsut above
	Data* deserializedD = Serializer::deserialize(serializedD);

	// Compare original Data object pointer with the deserialized pointer
	if (&d == deserializedD) {
		std::cout << "The original and deserialized pointers are equal." << std::endl;
	} else {
		std::cout << "The original and deserialized pointers are not equal." << std::endl;
	}

	// Compare data members of the original and deserialized Data objects
	if (d.someData == deserializedD->someData) {
		std::cout << "The original and deserialized data members are equal." << std::endl;
	} else {
		std::cout << "The original and deserialized data members are not equal." << std::endl;}

	// Original address of d is the same as the deserializedD !
	std::cout << std::endl;
	std::cout << "Data			: " << &d << std::endl;
	std::cout << "serialized		: " << serializedD << std::endl;
	std::cout << "deserialized raw	: " << deserializedD << std::endl;

	return 0;
}

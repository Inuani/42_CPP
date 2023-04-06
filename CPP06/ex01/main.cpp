#include <iostream>
#include "Serializer.hpp"

int main() {
	// Step 1: Create a Data object and initialize its data members
	Data originalData;
	originalData.someData = 42;

	// Step 2: Serialize the Data object using the Serializer::serialize() method
	uintptr_t serializedData = Serializer::serialize(&originalData);

	// Step 3: Deserialize the uintptr_t value obtained in the previous step
	Data* deserializedData = Serializer::deserialize(serializedData);

	// Step 4: Compare the original Data object pointer with the deserialized pointer
	if (&originalData == deserializedData) {
		std::cout << "The original and deserialized pointers are equal." << std::endl;
	} else {
		std::cout << "The original and deserialized pointers are not equal." << std::endl;
	}

	// Step 5 (Optional): Compare the data members of the original and deserialized Data objects
	if (originalData.someData == deserializedData->someData) {
		std::cout << "The original and deserialized data members are equal." << std::endl;
	} else {
		std::cout << "The original and deserialized data members are not equal." << std::endl;}
	return 0;
}

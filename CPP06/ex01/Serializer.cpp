#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer() {}

Serializer::~Serializer() {}

// here we convert a pointer to Data (Data*) to unsigned integer (uintptr_t)
uintptr_t	Serializer::serialize(Data* ptr)
{
	// convert a given pointer to an unsigned int of type uintptr_t
	return reinterpret_cast<uintptr_t>(ptr);
	// returns the uintptr_t value that represents the original address of the Data object.
}


Data*	Serializer::deserialize(uintptr_t raw)
{
	// convert uintptr_t raw back to a pointer to a Data object (Data*)
	return reinterpret_cast<Data*>(raw);
}

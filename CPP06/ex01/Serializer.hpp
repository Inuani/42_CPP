#include <iostream>

#ifndef Serializer_HPP
# define Serializer_HPP

struct	Data {
	unsigned int	someData;
};

class Serializer {

public:

	static	uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
};

// reinterpret_cast convert any pointer type to another pointer type,
// or a pointer to an integral type and vice versa.
// When using reinterpret_cast, you're telling the compiler 
// to treat the raw memory at a specific address as a different type.

// This can be useful in specific cases,
// ex : when you need to store a pointer in a data structure 
// that only accepts integral types or 
// when you need to perform low-level manipulation of memory addresses.

#endif

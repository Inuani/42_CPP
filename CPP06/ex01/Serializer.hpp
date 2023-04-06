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

#endif

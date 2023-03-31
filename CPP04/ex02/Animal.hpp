#include <iostream>

#ifndef Animal_HPP
# define Animal_HPP

class AAnimal {

public:

	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& src);
	virtual ~AAnimal();

	AAnimal& 		operator=(const AAnimal& rhs);
	virtual void			makeSound() const = 0;
	void			setType(const std::string& type);
	const std::string&	getType() const;
	virtual std::string* getIdeas() = 0;

private:

	std::string	_type;

};

#endif

#include <iostream>

#ifndef Brain_HPP
# define Brain_HPP

class Brain {

public:

	Brain();
	Brain(const Brain& src);
	~Brain();

	Brain& operator=(const Brain& rhs);

	std::string* getIdeas();
	void	setIdea(size_t i, const std::string& idea);

private:

	std::string	_ideas[100];

};

#endif

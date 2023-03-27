#include <iostream>
#include <fstream>

#ifndef STRINGREP_HPP
# define STRINGREP_HPP

class StringRep {

	public :

	StringRep(const std::string& s2Rep, const std::string& repS, const std::string& infileStr);
	~StringRep();

	void	replaceStr();
	std::string	getOutfileStr() const;

	private :

	std::string	_s2Rep;
	std::string	_repS;
	std::string	_infileStr;
	std::string	_outfileStr;

};

# endif

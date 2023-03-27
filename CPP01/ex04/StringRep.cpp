#include "StringRep.hpp"
#include <iostream>

StringRep::StringRep(const std::string& s2Rep, const std::string& repS, const std::string& infileStr) : _s2Rep(s2Rep), _repS(repS), _infileStr(infileStr)
{
	replaceStr();
}

StringRep::~StringRep()
{
}

void	StringRep::replaceStr()
{
	size_t	start = 0;
	size_t	end = 0;

	while((end = _infileStr.find(_s2Rep, start)) != std::string::npos)
	{
		_outfileStr += _infileStr.substr(start, end - start);
		_outfileStr += _repS;
		start = end + _s2Rep.length();
	}
	_outfileStr += _infileStr.substr(start);
}

std::string	StringRep::getOutfileStr() const
{
	return _outfileStr;
}

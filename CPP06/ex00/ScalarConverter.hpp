#include <iostream>

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

class ScalarConverter {

public:

	~ScalarConverter();
	//static so that it can be called without an instance of the class !
	static void	convert(const std::string& input);

private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& rhs);

	static bool	isChar(const std::string& input);
	static bool	isInt(const std::string& input);
	static bool	isFloat(const std::string& input);
	static bool isDouble(const std::string& input);

	static char		str2Char(const std::string& input);
	static int		str2Int(const std::string& input);
	static float	str2Float(const std::string& input);
	static double	str2Double(const std::string& input);

	static void		caseChar(const std::string& input);
	static void		caseInt(const std::string& input);
	static void		caseFloat(const std::string& input);
	static void		caseDouble(const std::string& input);

	static double	handleSpecial(const std::string& input);
	// static float	handleSpecialFloat(const std::string& input);

	struct Checker {
		std::string _type;
		bool (*func)(const std::string&);
	};

	static Checker _checkers[4];

};

#endif

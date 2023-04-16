#include <iostream>
#include <map>

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange {

public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& rhs);

	void			handleInputFile(const std::string& fileName);
	void			loadExchangeRates(const std::string& ratesFile);
	void			parseInputFile(std::ifstream& ifsInputFile);
	std::string		valiDate(const std::string& date);
	float			getBtcRate(const std::string& date);

private:

	std::map<std::string, float>	_exRates;

};

#endif

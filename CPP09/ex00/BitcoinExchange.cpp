#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream> // string stream interoperation btw stream buffers and string objects

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	_exRates = src._exRates;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	_exRates = rhs._exRates;
	return *this;
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int	maxDaysMonth(int month, int year) {
	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (month == 2 && isLeapYear(year) ? 29 : daysInMonth[month - 1]);
}

std::string		BitcoinExchange::valiDate(const std::string& date) {
	int					year, month, day;
	char				delim1, delim2;
	std::istringstream	ssDate(date);

	ssDate >> year >> delim1 >> month >> delim2 >> day;

	if(!ssDate || delim1 != '-' || delim2 != '-')
		return (std::string());
	if(year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > maxDaysMonth(month, year))
		return (std::string());
	return date;
}

float	BitcoinExchange::getBtcRate(const std::string& date) {
	if (_exRates.find(date) != _exRates.end())
		return _exRates[date];
	else {
		
		std::map<std::string, float>::iterator it = _exRates.lower_bound(date); // return it to the 1st element (date) greater than date passed as param
		// lower_bound: When comparing strings, the standard lexicographical comparison is used.
		// In "yyyy-mm-dd" format, lexicographical ordering coincides with chronological order of dates.
		if (it != _exRates.begin()) {
			--it;
			return it->second; // to return the acctual value (second element in the map, the 1st is the key !)
		}
		else
			return 0.0f;
	}
}

void	BitcoinExchange::parseInputFile(std::ifstream& ifsInputFile) {
	std::string	line;

	while (getline(ifsInputFile, line)) {
		std::istringstream	ss(line);
		std::string			date;
		float				money;
		
		getline(ss, date, '|');
		date = valiDate(date);
		if (date.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Now the stream ss is positioned after the | delim
		ss >> money;
		if (money < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (money > 1000) {
			std::cout << "Error: too large a number" << std::endl;
			continue;
		}
		float rate = getBtcRate(date);
		float res = rate * money;
		std::cout << date << "=> " << money << " = " << res << std::endl;
	}
}

void	BitcoinExchange::handleInputFile(const std::string& filename) {
	std::string::size_type extPos = filename.find('.'); // return an int that corresponds to the position of '.'
	if (extPos == std::string::npos || filename.substr(extPos) != ".csv") // npos = value returned by find() when unable to find the character?substring
		throw std::runtime_error("Input file must be a .csv file.");
	std::ifstream	ifs(filename);
	if (!ifs.is_open())
		throw std::runtime_error("Input file can not be opened.");
	parseInputFile(ifs);

	ifs.close();
}

void	BitcoinExchange::loadExchangeRates(const std::string& ratesFile)
{
	std::ifstream	ifs(ratesFile); // Used to read input from a file (like std::cin to read input from console)
	if (!ifs.is_open())
		throw std::runtime_error("Exchange rates file can not be opened.");
	std::string	line;
	while (getline(ifs, line)) {
		std::istringstream ss(line); 
		std::string	date;
		float		rate;
		getline(ss, date, ','); // getline(input stream to read from, string to store result, delimiter.
		ss >> rate;	// Read from input stream : >> operator on float it recognizes characters that make up a float number
					// Skips whitespace and stops reading when it encounters character that cannot be part of a float, such as comma or space.
		_exRates[date] = rate; // using [] operator with map to insert a new key-value pair in the map. Map adjust its size automatically.
	}
	ifs.close();
}

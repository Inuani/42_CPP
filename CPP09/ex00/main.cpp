#include <iostream>
#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if (ac == 2) {
		std::string	inputFile(av[1]);
		std::string	ratesFile = "data.csv";
		BitcoinExchange btc;
		try {
			btc.loadExchangeRates(ratesFile); }
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
		try {
			btc.handleInputFile(inputFile); }
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 2;
		}
		
	}
	else
		std::cerr << "Error: usage: ./btc <filename>.csv" <<std::endl;
	return 0;
}

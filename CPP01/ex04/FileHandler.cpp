#include "FileHandler.hpp"
#include <iostream>
#include <fstream>

FileHandler::FileHandler(const std::string &fileName) : _fileName(fileName), _outfileName(fileName + ".replace")
{
	readFile(_fileName);
}

FileHandler::~FileHandler()
{
}

void FileHandler::readFile(std::string file)
{
	std::ifstream	ifs(file);
	std::string		line;

	if (!ifs.is_open())
	{
		std::cerr << "Error: unable to open file '" << file << "'" << std::endl;
		std::exit(1);
	}
	while (std::getline(ifs, line))
	{
		_infileStr += line;
		_infileStr += '\n';
	}
	ifs.close();
}

std::string	FileHandler::getInfileStr() const
{
	return _infileStr;
}

void	FileHandler::copyStrInOutfileStream(const std::string& outfileStr)
{
	_ofs.open(_outfileName, std::ios::out | std::ios::trunc);
	if (!_ofs.is_open())
	{
		std::cerr << "Error: unable to open file '" << _outfileName << "'" << std::endl;
		std::exit(1);
	}
	_ofs << outfileStr;
	_ofs.close();
}

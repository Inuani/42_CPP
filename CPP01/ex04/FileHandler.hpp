#include <iostream>
#include <fstream>

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

class FileHandler {

	public :

	FileHandler(const std::string &fileName);
	~FileHandler();

	std::string	getInfileStr() const;
	void		copyStrInOutfileStream(const std::string& outfileStr);

	private :

	void	readFile(const std::string file);
	std::string		_fileName;
	std::string		_infileStr;
	std::string		_outfileName;
	std::ofstream	_ofs;
};

# endif

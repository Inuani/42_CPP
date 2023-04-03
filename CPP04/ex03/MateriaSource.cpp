#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _count(0)
{
	for(int i = 0; i < 4; ++i)
		_materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src) : _count(src._count)
{
	for (int i = 0; i < 4; ++i)
		_materias[i] = nullptr;
	for (int i = 0; i < src._count; ++i)
		_materias[i] = src._materias[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; ++i)
	{
		if (_materias[i] != nullptr)
			delete _materias[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < _count; ++i)
		delete _materias[i];
	
	_count = 0;
	for (int i = 0; i < rhs._count; ++i)
		_materias[i] = rhs._materias[i]->clone();
	_count = rhs._count;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* mat)
{
	if (mat != nullptr && _count < 4)
	{
		_materias[_count] = mat;
		++_count;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return nullptr;
}




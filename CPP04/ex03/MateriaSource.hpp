#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& src);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);
	void	learnMateria(AMateria* mat);
	AMateria*	createMateria(const std::string& type);

private:
	AMateria*	_materias[4];
	int			_count;

};

#endif

 // learned Materia allows characters to equip and use Materia, 
 // without having to create new instances of each type of Materia object. 
 // MateriaSource handles the creation and storage of Materia objects,
 // while the Character class handles the management and use of the Materia objects.


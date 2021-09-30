#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice();
	virtual ~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);

	virtual AMateria *clone() const;

	virtual void use(ICharacter &target);
};


#endif
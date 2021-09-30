#ifndef _CURE_HPP_
#define _CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria{

public:

	Cure();
	virtual ~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	virtual AMateria *clone() const;

	virtual void use(ICharacter &target);
};


#endif
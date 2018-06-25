#ifndef EXOTICO_H
#define EXOTICO_H

#include "../include/animalSilvestre.h"
#include <string>

class Exotico: public AnimalSilvestre
{
protected:
	std::string m_pais_origem;
public:
	std::string getPais_origem();
	void setPais_origem(std::string);
};

#endif
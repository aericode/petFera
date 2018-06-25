#ifndef MAMIFERO_H
#define MAMIFERO_H
#include "animal.h"
#include <string>

class Mamifero: public Animal
{
protected:
	std::string m_cor_pelo;
public:
	std::string getCor_pelo();
	void setCor_pelo(std::string);
};

#endif
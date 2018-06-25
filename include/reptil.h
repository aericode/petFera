#ifndef REPTIL_H
#define REPTIL_H
#include "animal.h"
#include <string>

class Reptil: public Animal
{
protected:
	bool m_venenoso;
	std::string m_tipo_veneno;
public:
	bool getVenenoso();
	void setVenenoso(bool);
	std::string getTipo_veneno();
	void setTipo_veneno(std::string);
};

#endif
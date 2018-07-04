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
	Reptil(int
		,std::string
		,std::string
		,std::string
		,char
		,float
		,std::string
		,std::shared_ptr<Funcionario>
		,std::shared_ptr<Funcionario>
		,std::string);
	~Reptil();
	bool getVenenoso();
	void setVenenoso(bool);
	std::string getTipo_veneno();
	void setTipo_veneno(std::string);
};

#endif
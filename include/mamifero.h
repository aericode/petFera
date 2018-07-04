#ifndef MAMIFERO_H
#define MAMIFERO_H
#include "animal.h"
#include <string>

class Mamifero: public Animal
{
protected:
	std::string m_cor_pelo;
public:
	Mamifero(int
		,std::string
		,std::string
		,std::string
		,char
		,float
		,std::string
		,std::shared_ptr<Funcionario>
		,std::shared_ptr<Funcionario>
		,std::string);
	~Mamifero();
	std::string getCor_pelo();
	void setCor_pelo(std::string);
};

#endif
#ifndef TRATADOR_H
#define TRATADOR_H
#include "funcionario.h"
#include <string>

class Tratador : public Funcionario
{
public:
	Tratador();
	Tratador(int,std::string,std::string,std::string,short int,std::string,char,std::string);
	~Tratador();
};


#endif
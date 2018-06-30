#ifndef TRATADOR_H
#define TRATADOR_H
#include "funcionario.h"
#include <string>

class Tratador : public Funcionario
{
private:
	std::string emiteSave();
public:
	Tratador();
	Tratador(int,std::string,std::string,short int,std::string,char,std::string);
	~Tratador();
};


#endif
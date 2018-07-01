#ifndef VETERINARIO_H
#define VETERINARIO_H
#include "funcionario.h"

class Veterinario : public Funcionario
{
public:
	Veterinario();
	Veterinario(int,std::string,std::string,std::string,short int,std::string,char,std::string);
	~Veterinario();
};


#endif
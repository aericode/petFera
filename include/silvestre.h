#ifndef NATIVO_H
#define NATIVO_H

#include "../include/animalSilvestre.h"
#include <string>

class Nativo: public AnimalSilvestre
{
protected:
	std::string m_uf_origem;
	std::string m_autorizacao;
public:
	std::string getUf_origem();
	void setUf_origem(std::string);
	std::string getAutorizacao();
	void setAutorizacao(std::string);
};

#endif
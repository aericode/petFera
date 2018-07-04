#ifndef ANFIBIO_H
#define ANFIBIO_H
#include "animal.h"
#include <string>

class Anfibio: public Animal
{
protected:
	int m_total_mudas;
	std::string m_ultima_muda;
public:
	Anfibio(int
		,std::string
		,std::string
		,std::string
		,char
		,float
		,std::string
		,std::shared_ptr<Funcionario>
		,std::shared_ptr<Funcionario>
		,std::string);
	~Anfibio();
	int getTotal_mudas();
	void setTotal_mudas(int);
	std::string getUltima_muda();
	void setUltima_muda(std::string);
};

#endif
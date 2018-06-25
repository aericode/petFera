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
	int getTotal_mudas();
	void setTotal_mudas(int);
	std::string getUltima_muda();
	void setUltima_muda(std::string);
};

#endif
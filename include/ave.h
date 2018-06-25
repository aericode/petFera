#ifndef AVE_H
#define AVE_H
#include "animal.h"
#include <string>

class Ave: public Animal
{
protected:
	int m_tamanho_bico;
	int m_envergadura;
public:
	int getTamanho_bico();
	void setTamanho_bico(int);
	int getEnvergadura();
	void setEnvergadura(int);
};

#endif
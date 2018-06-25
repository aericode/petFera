#ifndef ANIMAL_SILVESTRE_H
#define ANIMAL_SILVESTRE_H
#include <string>

class AnimalSilvestre
{
protected:
	std::string m_ibama;
public:
	std::string getIbama();
	void setIbama(std::string);
};

#endif
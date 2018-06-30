#ifndef ANIMAL_H
#define ANIMAL_H
#include "tratador.h"
#include "veterinario.h"
#include <string>
#include <memory>

class Animal
{
protected:
	int m_id;
	std::string m_classe;
	std::string m_nome; //especie do animal
	std::string m_cientifico;
	char m_sexo;
	float m_tamanho;
	std::string m_dieta;
	std::shared_ptr<Funcionario> m_veterinario;
	std::shared_ptr<Tratador> m_tratador;
	std::string m_batismo;
	
public:
	Animal();
	Animal  (int
			,std::string
			,std::string
			,std::string
			,char
			,float
			,std::string
			,std::shared_ptr<Funcionario>
			//,std::shared_ptr<Tratador>&
			,std::string);
	~Animal();
	int getId();
	void setId(int);
	std::string getClasse();
	void setClasse(std::string);
	std::string getNome();
	void setNome(std::string);
	std::string getCientifico();
	void setCientifico(std::string);
	char getSexo();
	void setSexo(char);
	float getTamanho();
	void setTamanho(float);
	std::string getDieta();
	void setDieta(std::string);
	std::string getBatismo();
	void setBatismo(std::string);
	/*
	std::shared_ptr<Veterinario> getVeterinario();
	void setVeterinario(std::shared_ptr<Veterinario>);
	std::shared_ptr<Tratador> getTratador();
	void setTratador(std::shared_ptr<Tratador>);
	*/
	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};



#endif
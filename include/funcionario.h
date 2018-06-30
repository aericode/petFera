#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <string>

class Funcionario
{
protected:
	int m_id;
	std::string m_nome;
	std::string m_cpf;
	short int m_idade;
	std::string m_tipo_sanguineo;
	char m_fatorRH;
	std::string m_especialidade;
public:
	Funcionario();
	//Funcionario(int,std::string,std::string,short int,std::string,char,std::string);
	~Funcionario();
	int getId();
	void setId(int);
	std::string getNome();
	void setNome(std::string);
	std::string getCpf();
	void setCpf(std::string);
	short int getIdade();
	void setIdade(short int);
	std::string getTipo_sanguineo();
	void setTipo_sanguineo(std::string);
	char getFatorRH();
	void setFatorRH(char);
	std::string getEspecialidade();
	void setEspecialidade(std::string);

	friend std::ostream& operator<<(std::ostream& os, const Funcionario& funcionario);
};



#endif
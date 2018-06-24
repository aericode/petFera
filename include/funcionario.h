#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

class Funcionario
{
protected:
	int m_id;
	std::string m_nome;
	std::string m_cpf;
	short int m_idade;
	char m_tipo_sanguineo;
	char m_fatorRH;
	std::string m_especialidade;
public:
	int getId();
	void setId(int);
	std::string getNome();
	void setNome(std::string);
	std::string getCpf();
	void setCpf(std::string);
	short int getIdade();
	void setIdade(short int);
	char getTipo_sanguineo();
	void setTipo_sanguineo(char);
	char getFatorRH();
	void setFatorRH(char);
	std::string getEspecialidade();
	void setEspecialidade(std::string);
};



#endif
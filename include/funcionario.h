#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario
{
protected:
	int id;
	std::string nome;
	std::string cpf;
	short int idade;
	char tipo_sanguineo;
	char fatorRH;
	std::string especialidade;
public:
	int getId();
	void setId(int);
	std::string getNome();
	void setNome(std::string);
	std::string getCpf(std::string);
	void setCpf(int);
	short int getIdade();
	void setIdade(short int);
	char getTipo_sanguineo();
	void setTipo_sanguineo(char);
	char getFatorRH();
	void setFatorRH(char);
	std::string getEspecialidade();
	void setEspecialidade(std::string);
}



#endif
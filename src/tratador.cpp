#include "../include/funcionario.h"
#include "../include/tratador.h"


Tratador::Tratador(){}
Tratador::Tratador  (int id
					,std::string nome
					,std::string cpf
					,short int idade
					,std::string tipo_sanguineo
					,char fatorRH
					,std::string especialidade){Funcionario(id,nome,cpf,idade,tipo_sanguineo,fatorRH,especialidade);}
Tratador::~Tratador(){}
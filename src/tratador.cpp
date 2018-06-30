#include "../include/funcionario.h"
#include "../include/tratador.h"
#include <iostream>
#include <string>

Tratador::Tratador(){}
Tratador::Tratador  (int id,std::string nome,std::string cpf,short int idade
					,std::string tipo_sanguineo,char fatorRH,std::string especialidade){ 
																						 m_id = id;
																						 m_nome = nome;
																						 m_cpf = cpf;
																						 m_idade = idade;
																						 m_tipo_sanguineo = tipo_sanguineo;
																						 m_fatorRH = fatorRH;
																						 m_especialidade = especialidade;}
Tratador::~Tratador(){}

std::string Tratador::emiteSave(){ //transformar em função com template
	std::string dataSave;
	std::string separador = ";";
	std::string atribuicao = "Tratador";


	dataSave = std::to_string(m_id)    + separador
			 + atribuicao              + separador
			 + m_nome                  + separador
			 + m_cpf                   + separador
			 + std::to_string(m_idade) + separador
	         + m_tipo_sanguineo        + separador
			 + m_fatorRH               + separador
			 + m_especialidade         + separador
			 + "\n";


	std::cout<< dataSave << std::endl;
	return dataSave;
}
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


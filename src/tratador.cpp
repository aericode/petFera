/**
  * @file 		tratador.cpp
  * @brief 		construtor
  * @details 	especificidades da classe tratador (no momento, nenhuma)
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */
#include "funcionario.h"
#include "tratador.h"
#include <iostream>
#include <string>

Tratador::Tratador(){}
Tratador::Tratador  (int id,std::string tipo_funcionario,std::string nome,std::string cpf
					,short int idade,std::string tipo_sanguineo,char fatorRH,std::string especialidade){ 
																										 m_id = id;
																										 m_nome = nome;
																										 m_tipo_funcionario = tipo_funcionario;
																										 m_cpf = cpf;
																										 m_idade = idade;
																										 m_tipo_sanguineo = tipo_sanguineo;
																										 m_fatorRH = fatorRH;
																										 m_especialidade = especialidade;}
Tratador::~Tratador(){}
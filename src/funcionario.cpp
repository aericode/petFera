/**
  * @file 		funcionario.cpp
  * @brief 		Getter-setters e emissor de strings para armazenamento (Loja::salvarFuncionarios())
  * @details 	Sobrecarga do operador de impressão e salvar. Além dos elementos padrão. Construtor nas subclasses.
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */
#include <iostream>
#include <fstream>
#include <string> 

#include "funcionario.h"

Funcionario::Funcionario(){}
Funcionario::~Funcionario(){}

int Funcionario::getId(){return m_id;}
void Funcionario::setId(int id){m_id = id;}
std::string Funcionario::getNome(){return m_nome;}
void Funcionario::setNome(std::string nome){m_nome = nome;}
std::string Funcionario::getCpf(){return m_cpf;}
void Funcionario::setCpf(std::string cpf){m_cpf = cpf;}
short int Funcionario::getIdade(){return m_idade;}
void Funcionario::setIdade(short int idade){m_idade = idade;}
std::string Funcionario::getTipo_sanguineo(){return m_tipo_sanguineo;}
void Funcionario::setTipo_sanguineo(std::string tipo_sanguineo){m_tipo_sanguineo = tipo_sanguineo;}
char Funcionario::getFatorRH(){return m_fatorRH;}
void Funcionario::setFatorRH(char fatorRH){m_fatorRH = fatorRH;}
std::string Funcionario::getEspecialidade(){return m_especialidade;}
void Funcionario::setEspecialidade(std::string especialidade){m_especialidade = especialidade;}

std::string Funcionario::getTipo_funcionario(){return m_tipo_funcionario;}
void Funcionario::setTipo_funcionario(std::string tipo_funcionario){m_tipo_funcionario = tipo_funcionario;}


/**
 * Gera uma string que pode ser lida pelo carregador do petFera
 * @brief por meio de sucetivas concatenações e conversões ao formato de string, gera um texto válido para leitura na próxima inicialização 
 * @return uma string válida para leitura por (Loja::carregaFuncionarios()) na próxima inicialização
 */
std::string Funcionario::emiteSave(){ //transformar em função com template
	std::string dataSave;
	std::string separador = ";";


	dataSave = std::to_string(m_id)    + separador
			 + m_tipo_funcionario      + separador
			 + m_nome                  + separador
			 + m_cpf                   + separador
			 + std::to_string(m_idade) + separador
			 + m_tipo_sanguineo        + separador
			 + m_fatorRH               + separador
			 + m_especialidade;

	return dataSave;
}


/**
 * Mostra na tela informações do funcionário
 */
std::ostream& operator<<(std::ostream& os, const Funcionario& funcionario){
	os<<"ID: "<< funcionario.m_id << std::endl
	  <<"Nome: "<< funcionario.m_nome << std::endl
	  <<"CPF: "<< funcionario.m_cpf << std::endl
	  <<"Idade: "<< funcionario.m_idade << std::endl
	  <<"Tipo sanguineo "<< funcionario.m_tipo_sanguineo<<funcionario.m_fatorRH << std::endl
	  <<"Especialidade: "<< funcionario.m_especialidade << std::endl;

	return os;
}
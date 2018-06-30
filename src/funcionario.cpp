#include <iostream>
#include <fstream>
#include <string> 

#include "../include/funcionario.h"

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

std::string Funcionario::emiteSave(){ //transformar em função com template
	std::string dataSave;
	std::string separador = ";";
	std::string atribuicao = "Funcionario";


	dataSave = std::to_string(m_id)    + separador
			 + atribuicao              + separador
			 + m_nome                  + separador
			 + m_cpf                   + separador
			 + std::to_string(m_idade) + separador
	         + m_tipo_sanguineo        + separador
			 + m_fatorRH               + separador
			 + m_especialidade         + "\n";


	std::cout<< dataSave << std::endl;
	return dataSave;
}

std::ostream& operator<<(std::ostream& os, const Funcionario& funcionario){
	os<<"ID: "<< funcionario.m_id << std::endl
	  <<"Nome: "<< funcionario.m_nome << std::endl
	  <<"CPF: "<< funcionario.m_cpf << std::endl
	  <<"Idade: "<< funcionario.m_idade << std::endl
	  <<"Tipo sanguineo "<< funcionario.m_tipo_sanguineo<<funcionario.m_fatorRH << std::endl
	  <<"Especialidade: "<< funcionario.m_especialidade << std::endl;

	return os;
}
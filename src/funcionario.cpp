#include <iostream>
#include <fstream>
#include <string> 

#include "../include/funcionario.h"

Funcionario::Funcionario(int id,std::string nome,std::string cpf,int idade
						,std::string tipo_sanguineo,char fatorRH,std::string especialidade) 
																				 :m_id(id)
																				 ,m_nome(nome)
																				 ,m_cpf(cpf)
																				 ,m_idade(idade)
																				 ,m_tipo_sanguineo(tipo_sanguineo)
																				 ,m_fatorRH(fatorRH)
																				 ,m_especialidade(especialidade){}
/*{
	
	std::string temp;
	std::string::size_type sz; // alias do size_t de string

	std::ifstream ip("./data/funcionario_db.csv");
	
	if(!ip.is_open()){
		std::cout << "ERRO: arquivo funcionario_db.csv nao foi aberto"<<std::endl;
	}
	

	//ID
	getline(ip,temp,';');
	m_id = std::stoi(temp,&sz);//converte a string temp em int

	//IGNORANDO SEGUNDO PARAMETRO
	getline(ip,temp,';');

	//NOME
	getline(ip,m_nome,';');

	//CPF
	getline(ip,m_cpf,';');

	//IDADE
	getline(ip,temp,';');
	m_idade = (short)std::stoi(temp,&sz);//converte a string temp em int

	//TIPO SANGUINEO
	getline(ip,m_tipo_sanguineo,';');

	//FATOR RH
	getline(ip,temp,';');
	m_fatorRH = *temp.c_str();//converte a string temp em char

	//ESPECIALIDADE
	getline(ip,m_especialidade,'\n');
	
}
*/
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

std::ostream& operator<<(std::ostream& os, const Funcionario& funcionario){
	os<<"ID: "<< funcionario.m_id << std::endl
	  <<"Nome: "<< funcionario.m_nome << std::endl
	  <<"CPF: "<< funcionario.m_cpf << std::endl
	  <<"Idade: "<< funcionario.m_idade << std::endl
	  <<"Tipo sanguineo "<< funcionario.m_tipo_sanguineo<<funcionario.m_fatorRH << std::endl
	  <<"Especialidade: "<< funcionario.m_especialidade << std::endl;

	return os;
}
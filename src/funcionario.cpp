#include "../include/funcionario.h"
#include <string>

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
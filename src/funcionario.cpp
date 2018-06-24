#include "funcionario.h"

int funcionario::getId(){return m_id;}
void funcionario::setId(int id){m_id = id;}
std::string funcionario::getNome(){return m_nome;}
void funcionario::setNome(std::string nome){m_nome = nome;}
std::string funcionario::getCpf(){return m_cpf;}
void funcionario::setCpf(std::string cpf){m_cpf = cpf;}
short int funcionario::getIdade(){return m_idade;}
void funcionario::setIdade(short int){m_idade = idade;}
char funcionario::getTipo_sanguineo(){return m_tipo_sanguineo;}
void funcionario::setTipo_sanguineo(char tipo_sanguineo){m_tipo_sanguineo = tipo_sanguineo;}
char funcionario::getFatorRH(){return m_FatorRH;}
void funcionario::setFatorRH(char fatorRH){m_FatorRH = fatorRH;}
std::string funcionario::getEspecialidade(){return m_especialidade;}
void funcionario::setEspecialidade(std::string especialidade){m_especialidade = especialidade;}
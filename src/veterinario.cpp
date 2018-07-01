#include "../include/funcionario.h"
#include "../include/veterinario.h"

Veterinario::Veterinario(){}
Veterinario::Veterinario(int id,std::string tipo_funcionario,std::string nome,std::string cpf
						,short int idade,std::string tipo_sanguineo,char fatorRH,std::string especialidade){ 
																											 m_id = id;
																											 m_nome = nome;
																											 m_tipo_funcionario = tipo_funcionario;
																											 m_cpf = cpf;
																											 m_idade = idade;
																											 m_tipo_sanguineo = tipo_sanguineo;
																											 m_fatorRH = fatorRH;
																											 m_especialidade = especialidade;}
Veterinario::~Veterinario(){}
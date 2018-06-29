#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <map>

#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/tratador.h"
#include "../include/animal.h"
#include "../include/reptil.h"
#include "../include/anfibio.h"
#include "../include/mamifero.h"
#include "../include/animalSilvestre.h"
#include "../include/exotico.h"
#include "../include/nativo.h"
#include "../include/aveExotica.h"
#include "../include/aveNativa.h"
#include "../include/loja.h"



void Loja::carregarFuncionarios(){
	std::string tipo_funcionario;
	std::string::size_type sz; // alias do size_t de string
	std::string temp;

	std::ifstream ip("./data/funcionario_db.csv");
	
	if(!ip.is_open()){
		std::cout << "ERRO: arquivo funcionario_db.csv nao foi aberto"<<std::endl;
	}

	int func_id;
	std::string func_nome;
	std::string func_cpf;
	short int func_idade;
	std::string func_tipo_sanguineo;
	char func_fatorRH;
	std::string func_especialidade;
	
	while(ip.good()){
		//ID
		getline(ip,temp,';');
		func_id = std::stoi(temp,&sz);//converte a string temp em int

		//TIPO PARA INICIALIZAÇÃO
		getline(ip,tipo_funcionario,';');

		//NOME
		getline(ip,func_nome,';');

		//CPF
		getline(ip,func_cpf,';');

		//IDADE
		getline(ip,temp,';');
		func_idade = (short)std::stoi(temp,&sz);//converte a string temp em int

		//TIPO SANGUINEO
		getline(ip,func_tipo_sanguineo,';');

		//FATOR RH
		getline(ip,temp,';');
		func_fatorRH = *temp.c_str();//converte a string temp em char

		//ESPECIALIDADE
		getline(ip,func_especialidade,'\n');


		//INICIALIZAR O FUNCIONARIO
		if(tipo_funcionario=="Veterinario"){
			funcionario_db[func_id] = std::make_shared<Funcionario>(
														Funcionario	(func_id,func_nome,func_cpf,
																	func_idade,func_tipo_sanguineo,
																	func_fatorRH,func_especialidade));
		}

		if(tipo_funcionario=="Tratador"){
			funcionario_db[func_id] = std::make_shared<Funcionario>(
														Funcionario	(func_id,func_nome,func_cpf,
																	func_idade,func_tipo_sanguineo,
																	func_fatorRH,func_especialidade));
		}


	}
}

Loja::Loja(){
	Loja::carregarFuncionarios();
}

Loja::~Loja(){}

void Loja::func_imprimePorId(int func_id){
	std::cout<<*funcionario_db[func_id]<<std::endl;
}
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
	std::string::size_type sz; // alias do size_t de string
	std::string temp;

	std::ifstream ip("./data/funcionario_db.csv");
	
	if(!ip.is_open()){
		std::cout << "ERRO: arquivo funcionario_db.csv nao foi aberto"<<std::endl;
	}

	int func_id;
	std::string tipo_funcionario;
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
			funcionario_db[func_id] = std::make_shared<Veterinario>(
														Veterinario	(func_id,tipo_funcionario,func_nome,func_cpf,
																	func_idade,func_tipo_sanguineo,
																	func_fatorRH,func_especialidade));
		}

		if(tipo_funcionario=="Tratador"){
			funcionario_db[func_id] = std::make_shared<Tratador>(
														Tratador	(func_id,tipo_funcionario,func_nome,func_cpf,
																	func_idade,func_tipo_sanguineo,
																	func_fatorRH,func_especialidade));
		}


	}
}

void Loja::carregarAnimais(){
	int temp_int;
	std::string temp;
	std::string::size_type sz; // alias do size_t de string

	std::ifstream ip("./data/animal_db.csv");
	
	if(!ip.is_open()){
		std::cout << "ERRO: arquivo animal_db.csv nao foi aberto"<<std::endl;
	}

	int anim_id;
	std::string anim_classe;
	std::string anim_nome; //especie do animal
	std::string anim_cientifico;
	char anim_sexo;
	float anim_tamanho;
	std::string anim_dieta;
	std::shared_ptr<Funcionario> anim_veterinario;
	std::shared_ptr<Funcionario> anim_tratador;
	std::string anim_batismo;
	
	while(ip.good()){
		//ID
		getline(ip,temp,';');
		anim_id = std::stoi(temp,&sz);//converte a string temp em int

		//CLASSE
		getline(ip,anim_classe,';');

		//NOME (da especie)
		getline(ip,anim_nome,';');

		//NOME CIENTIFICO
		getline(ip,anim_cientifico,';');	

		//SEXO
		getline(ip,temp,';');
		anim_sexo = *temp.c_str();//converte a string temp em char

		//TAMANHO
		getline(ip,temp,';');
		anim_tamanho = ::atof(temp.c_str());//converte a string temp em float

		//DIETA
		getline(ip,anim_dieta,';');

		//VETERINARIO
		getline(ip,temp,';');//recebe o numero de registro do funcionario
		temp_int = std::stoi(temp,&sz);//converte esse numero em int
		anim_veterinario = funcionario_db[temp_int];

		//TRATADOR
		getline(ip,temp,';');//recebe o numero de registro do funcionario
		temp_int = std::stoi(temp,&sz);//converte esse numero em int
		anim_tratador = funcionario_db[temp_int];

		//BATISMO
		getline(ip,anim_batismo,'\n');
		
		//INICIALIZA ANIMAL
		animal_db[anim_id] = std::make_shared<Animal>(
													  Animal(anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
																
		}
}

void Loja::exibirFuncionarios(){
	for(auto it = funcionario_db.cbegin(); it != funcionario_db.cend(); ++it){
    	std::cout << *(it->second) << std::endl;
	}
}

void Loja::salvarFuncionarios(){
	std::ofstream op;//abreviação para output
	op.open("./data/funcionarioSave.csv");
	for(auto it = funcionario_db.cbegin(); it != funcionario_db.cend(); ++it){
    	op << it->second->emiteSave();
	}
	op.close();
}


Loja::Loja(){
	Loja::carregarFuncionarios();
	Loja::carregarAnimais();
}

Loja::~Loja(){}

void Loja::func_imprimePorId(int func_id){
	std::cout<<*funcionario_db[func_id]<<std::endl;
	//std::cout<<funcionario_db[func_id]->emiteSave()<<std::endl;
}

void Loja::anim_imprimePorId(int anim_id){
	std::cout<<*animal_db[anim_id]<<std::endl;
}
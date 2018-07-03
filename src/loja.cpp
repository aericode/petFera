#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <map>
#include <iterator>

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
	op.open("./data/funcionario_db.csv");
	for(auto it = funcionario_db.cbegin(); it != funcionario_db.cend();){//o sistema vai para a prox entrada do map, (next não funcionou para peek do próximo, ++it incrementa, e depois é comparado)
		std::string saveLine = it->second->emiteSave();//acessa o ponteiro do animal, associado à chave e chama uma string de save
		if(++it != funcionario_db.cend()) saveLine = saveLine + '\n';//não pode dar quebra de linha na última linha (um funcionario por linha)
    	op << saveLine;
	}
	op.close();
}

void Loja::salvarAnimais(){
	std::ofstream op;//abreviação para output
	op.open("./data/animal_db.csv");
	for(auto it = animal_db.cbegin(); it != animal_db.cend();){//o sistema vai para a prox entrada do map, (next não funcionou para peek do próximo, ++it incrementa, e depois é comparado)
		std::string saveLine = it->second->emiteSave();//acessa o ponteiro do animal, associado à chave e chama uma string de save
		if(++it != animal_db.cend()) saveLine = saveLine + '\n';//adiciona um espaço ao final de todas as linhas menos a última.
    	op << saveLine;
	}
	op.close();
}


Loja::Loja(){
	Loja::carregarFuncionarios();
	Loja::carregarAnimais();
}

Loja::~Loja(){
	Loja::salvarFuncionarios();
	Loja::salvarAnimais();
}


void Loja::adicionarFuncionario(){
	int func_id;
	std::string tipo_funcionario;
	std::string func_nome;
	std::string func_cpf;
	short int func_idade;
	std::string func_tipo_sanguineo;
	char func_fatorRH;
	std::string func_especialidade;

	try{
		//ID do funcionario
		std::cout<<"Digite o ID do novo funcionário"<<std::endl;
		std::cin>>func_id;
		if(!std::cin){throw 9;}//input léxico em campo numerico
		if(func_id<=0){throw 10;}//input negativo, aceitar somente numeros naturais
		if(funcionario_db.find(func_id) != funcionario_db.end()){throw 1;}//ERRO: ID em uso
		std::cin.ignore();//ignorar o a quebra de linha do cin
		
		
		//Tipo do funcionario
		std::cout<<"Digite a Função do novo funcionário"<<std::endl;
		std::getline(std::cin,tipo_funcionario);
		if(tipo_funcionario!="Veterinario"&&tipo_funcionario!="Tratador"){throw 2;}//ERRO: Informação inválida dada como input

		//Nome do funcionario
		std::cout<<"Digite o Nome do novo funcionário"<<std::endl;
		std::getline(std::cin,func_nome);
		if(func_nome.size()==0){throw 3;}//ERRO: campo obrigatorio não preenchido

		//CPF do funcionario
		std::cout<<"Digite o CPF do novo funcionário"<<std::endl;
		std::getline(std::cin,func_cpf);
		if(func_cpf.size()==0){throw 4;}//ERRO: campo obrigatorio não preenchido

		//Idade do funcionario
		std::cout<<"Digite a Idade do novo funcionário"<<std::endl;
		std::cin>>func_idade;
		if(!std::cin){throw 9;}//input léxico em campo numerico
		if(func_idade<18||func_idade>120){throw 5;}//Limite de idade
		std::cin.ignore();//ignorar o a quebra de linha do cin

		
		//Tipo sanguíneo do funcionario
		std::cout<<"Digite o Tipo sanguíneo do novo funcionário"<<std::endl;
		std::getline(std::cin,func_tipo_sanguineo);
		if (  func_tipo_sanguineo!="O"
			&&func_tipo_sanguineo!="A"
			&&func_tipo_sanguineo!="B"
			&&func_tipo_sanguineo!="AB"){throw 6;}//ERRO: Informação inválida dada como input

		//Fator RH do funcionario
		std::cout<<"Digite o fator RH do novo funcionário"<<std::endl;
		std::cin>>func_fatorRH;
		std::cin.ignore();//ignorar o a quebra de linha do cin
		if (func_fatorRH!='+' && func_fatorRH!='-'){throw 7;}//ERRO: Informação inválida dada como input

		
		//Especialidade do funcionario
		std::cout<<"Digite a especialidade do novo funcionário"<<std::endl;
		std::getline(std::cin,func_especialidade);//ignorar o a quebra de linha do cin
		if(func_especialidade.size()==0){throw 8;}//ERRO: campo obrigatorio não preenchido

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
	}catch(int error_code){
		//std::cout<<"ERRO "<<error_code<<std::endl;  //<<' '<<func_id<<std::endl;//usar input como parte da mensagem

		std::cout << "ERRO: ";
		switch(error_code)
		{
			case 1:
				std::cout << "o número "<< func_id <<" já é o ID de outro funcionário"<<std::endl;
				break;
			case 2:
				std::cout << "o sistema só aceita funções: Tratador e Veterinario"<<std::endl;
				break;
			case 3:
				std::cout << "o nome do funcionário é obrigatório para o cadastro"<<std::endl;
				break;
			case 4:
				std::cout << "o cpf do funcionário é obrigatório para o cadastro"<<std::endl;
				break;
			case 5:
				std::cout << "idade não aceita pelo sistema ou pela política de contratação da empresa"<<std::endl;
				break;
			case 6:
				std::cout << "insira um tipo sanguíneo válido para o registro do funcionário (A,B,AB,O)"<<std::endl;
				break;
			case 7:
				std::cout << "insira um fator RH válido para o registro do funcionário (+ , -)"<<std::endl;
				break;
			case 8:
				std::cout << "a especialidade do funcionário é obrigatória para o cadastro"<<std::endl;
				break;
			case 9:
				std::cout << "insira um número válido para prosseguir com o cadastro"<<std::endl;
				break;
			case 10:
				std::cout << "O cadastro só trabalha com numeros positivos"<<std::endl;
						  << "o valor 0 está reservado para quando não há um funcionário para uma determinada função"<<std::endl;
				break;

		}
	}

}


void Loja::adicionarAnimal(){
	int auxId;//o usuario digita e o programa busca no map o ponteiro correspondente

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


	//ID do animal
	std::cout<<"Digite o ID do novo animal"<<std::endl;
	std::cin>>anim_id;
	std::cin.ignore();//ignorar o a quebra de linha do cin

	//Tipo do animal
	std::cout<<"Digite a classe do novo animal"<<std::endl;
	std::getline(std::cin,anim_classe);

	//Nome do animal
	std::cout<<"Digite o nome da especie do novo animal"<<std::endl;
	std::getline(std::cin,anim_nome);

	//Nome científico do animal
	std::cout<<"Digite o nome científico do novo animal"<<std::endl;
	std::getline(std::cin,anim_cientifico);

	//Sexo do animal
	std::cout<<"Digite o sexo do novo animal"<<std::endl;
	std::cin>>anim_sexo;
	std::cin.ignore();//ignorar o a quebra de linha do cin

	//Tamanho do animal
	std::cout<<"Digite o tamanho do novo animal"<<std::endl;
	std::cin>>anim_tamanho;
	std::cin.ignore();//ignorar o a quebra de linha do cin

	//Dieta do animal
	std::cout<<"Digite a dieta do novo animal"<<std::endl;
	std::getline(std::cin,anim_dieta);

	//ID do veterinário
	std::cout<<"Digite o ID do veterinário responsável pelo novo animal"<<std::endl;
	std::cin>>auxId;
	anim_veterinario = funcionario_db[auxId];
	std::cin.ignore();//ignorar o a quebra de linha do cin

	//ID do tratador
	std::cout<<"Digite o ID do tratador responsável pelo novo animal"<<std::endl;
	std::cin>>auxId;
	anim_tratador = funcionario_db[auxId];
	std::cin.ignore();//ignorar o a quebra de linha do cin
	
	//Nome de batismo do animal
	std::cout<<"Digite o nome de batismo do novo animal"<<std::endl;
	std::getline(std::cin,anim_batismo);

	//INICIALIZA ANIMAL
		animal_db[anim_id] = std::make_shared<Animal>(
													  Animal(anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));

}

void Loja::removerFuncionario(){
	int func_id;
	std::cout<<"Qual o id do funcionario que você gostaria de remover do registro? "<<std::endl;
	std::cin>>func_id;
	std::cout<<"Removendo "<<funcionario_db[func_id]->getNome()<<std::endl;
	funcionario_db.erase(func_id);
}

void Loja::removerAnimal(){
	int anim_id;
	std::cout<<"Qual o id do animal que você gostaria de remover do registro? "<<std::endl;
	std::cin>>anim_id;
	std::cout<<"Removendo "<<animal_db[anim_id]->getBatismo()<<std::endl;
	animal_db.erase(anim_id);
}


void Loja::func_imprimePorId(int func_id){
	std::cout<<*funcionario_db[func_id]<<std::endl;
}

void Loja::anim_imprimePorId(int anim_id){
	std::cout<<*animal_db[anim_id]<<std::endl;
}
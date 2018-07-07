/**
  * @file 		loja.cpp
  * @brief 		Interface - Administração de dados e contâiners
  * @details 	Recebe dados via I/O e arquivo, e centraliza o tratamento de Exceções
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <map>
#include <iterator>
#include <ios>

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


/**
 * Inicializa um map de funcionarios com base em um arquivo previamente salvo
 * @brief trata exceções caso haja arquivo vazio ou inputs inválidos
 */
void Loja::carregarFuncionarios(){
	std::string::size_type sz; // alias do size_t de string
	std::string temp;

	std::ifstream ip("./data/funcionario_db.csv");
	try{//Verifica falhas de arquivo

		if(!ip.is_open()){throw 1;}// testa se o arquivo foi aberto (avisando caso tenha incializado novo arquivo)

		ip.seekg(0, std::ios::end); //testa se o arquivo está vazio (Ler uma string vazia atestaria erro de sintaxe)
		if (ip.tellg() == 0) {throw 2;}
		ip.seekg(0, std::ios::beg); //volta o ponteiro de get para o inicio do arquivo(O ponteiro fica em eof quando não resetado)


		int func_id;
		std::string func_id_error;
		std::string tipo_funcionario;
		std::string func_nome;
		std::string func_cpf;
		short int func_idade;
		std::string func_tipo_sanguineo;
		char func_fatorRH;
		std::string func_especialidade;

		try{//FALHAS DE SINTAXE
			while(ip.good()){
				//ID
				getline(ip,temp,';');
				func_id_error = temp;//carrega uma string preventiva para apontar o local do erro
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
					//utiliza o segundo dado para informar qual o tipo de objeto a ser inicializado
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
			
		}catch(...){
			std::cout<<"Erro de sintaxe, o registro de funcionário ID: "<< func_id_error <<" provocou falha no carregamento"<<std::endl;

		}

	}catch(int error_code){
		switch(error_code)
		{
			case 1:
				std::cout<<"Arquivo funcionario_db.csv não foi encontrado, inicializando novo registro"<<std::endl;
				break;
			case 2:
				std::cout<<"Registro de animais vazio, inicializando sem animais cadastrados"<<std::endl;
				break;
		}
	}
}


/**
 * Inicializa um map de animais com base em um arquivo previamente salvo
 * @brief trata exceções caso haja arquivo vazio ou inputs inválidos, sendo seu maior diferencial a busca no map para funcionários
 */
void Loja::carregarAnimais(){
	int temp_int;
	std::string temp;
	std::string::size_type sz; // alias do size_t de string

	std::ifstream ip("./data/animal_db.csv");
	

	try{

		if(!ip.is_open()){throw 1;}// testa se o arquivo foi aberto (avisando caso tenha incializado novo arquivo)

		ip.seekg(0, std::ios::end); //testa se o arquivo está vazio (Ler strings vazias atestaria erro de sintaxe)
		if (ip.tellg() == 0) {throw 2;}
		ip.seekg(0, std::ios::beg); //volta o ponteiro de get para o inicio do arquivo (eof caso não seja resetado)

		int anim_id;
		std::string anim_id_error;
		std::string anim_classe;
		std::string anim_nome; //especie do animal
		std::string anim_cientifico;
		char anim_sexo;
		float anim_tamanho;
		std::string anim_dieta;
		std::shared_ptr<Funcionario> anim_veterinario;
		std::shared_ptr<Funcionario> anim_tratador;
		std::string anim_batismo;
	
		try{//FALHAS DE SINTAXE
			while(ip.good()){
					//ID
					getline(ip,temp,';');
					anim_id_error = temp;//carrega uma string preventiva para apontar o local do erro
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
						//utiliza o segundo dado para informar qual o tipo de objeto a ser inicializado
					if(anim_classe=="Mammalia"){
						animal_db[anim_id] = std::make_shared<Mamifero>(
																Mamifero(anim_id, anim_classe, anim_nome
																		,anim_cientifico,anim_sexo, anim_tamanho
																		,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
					}

					if(anim_classe=="Reptilia"){
						animal_db[anim_id] = std::make_shared<Reptil>(
																Reptil  (anim_id, anim_classe, anim_nome
																		,anim_cientifico,anim_sexo, anim_tamanho
																		,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
					}

					if(anim_classe=="Amphibia"){
						animal_db[anim_id] = std::make_shared<Anfibio>(
																Anfibio (anim_id, anim_classe, anim_nome
																		,anim_cientifico,anim_sexo, anim_tamanho
																		,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
					}

					if(anim_classe=="Aves"){
						animal_db[anim_id] = std::make_shared<Ave>(
																Ave     (anim_id, anim_classe, anim_nome
																		,anim_cientifico,anim_sexo, anim_tamanho
																		,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));															
					}
				}
			}catch(...){
				std::cout<<"Erro de sintaxe, o registro de animal ID: "<< anim_id_error <<" provocou falha no carregamento"<<std::endl;

			}

		}catch(int error_code){
			switch(error_code){
				case 1:
					std::cout<<"Arquivo animal_db.csv não foi encontrado, inicializando novo registro"<<std::endl;
					break;
				case 2:
					std::cout<<"Registro de animais vazio, inicializando sem animais"<<std::endl;
					break;
				default:
					std::cout<<"Erro de sintaxe"<<std::endl;
			}
		}
	
}

/**
 * Percorre o map contendo os funcionários utilizando a sobrecarga de operador para exibir dados a respeito dele
 */
void Loja::exibirFuncionarios(){
	try{
		if(funcionario_db.empty()==true)throw;
		for(auto it = funcionario_db.cbegin(); it != funcionario_db.cend(); ++it){
	    	std::cout << *(it->second) << std::endl;
		}
	}catch(...){
		std::cout<<" não há funcionários cadastrados no sistema" << std::endl;
	}
}

/**
 * Percorre o map contendo os animais utilizando a sobrecarga de operador para exibir dados a respeito dele
 */
void Loja::exibirAnimais(){
	if(animal_db.empty()==true){
		std::cout<<"Nenhum animal cadastrado"<<std::endl;
		return;//evita erros de leitura
	}
	for(auto it = animal_db.cbegin(); it != animal_db.cend(); ++it){
    	std::cout << *(it->second) << std::endl;
	}
}
/**
 * Salva a unidade contida em um arquivo
 * @Brief O programa percorre o map, solicitando a cada integrante do mesmo que emita uma string, chamada por uma função presente nos membros. A string contém dados do membro, e é usada para manter as informações após fechar o programa
 */
void Loja::salvarFuncionarios(){
	std::ofstream op;//abreviação para output
	op.open("./data/funcionario_db.csv");
	try{
		if(funcionario_db.empty()==true)throw;
		for(auto it = funcionario_db.cbegin(); it != funcionario_db.cend();){//o sistema vai para a prox entrada do map, (next não funcionou para peek do próximo, ++it incrementa, e depois é comparado)
			std::string saveLine = it->second->emiteSave();//acessa o ponteiro do animal, associado à chave e chama uma string de save
			if(++it != funcionario_db.cend()) saveLine = saveLine + '\n';//não pode dar quebra de linha na última linha (um funcionario por linha)
	    	op << saveLine;
		}
	}catch(...){
		std::cout<<"Aviso: sem funcionários cadastrados no sistema" << std::endl;
	}
	op.close();
}
/**
 * Salva a unidade contida em um arquivo
 * @Brief O programa percorre o map, solicitando a cada integrante do mesmo que emita uma string, chamada por uma função presente nos membros. A string contém dados do membro, e é usada para manter as informações após fechar o programa
 */
void Loja::salvarAnimais(){
	std::ofstream op;//abreviação para output
	op.open("./data/animal_db.csv");
	try{
		if(animal_db.empty()==true)throw;
		for(auto it = animal_db.cbegin(); it != animal_db.cend();){//o sistema vai para a prox entrada do map, (next não funcionou para peek do próximo, ++it incrementa, e depois é comparado)
			std::string saveLine = it->second->emiteSave();//acessa o ponteiro do animal, associado à chave e chama uma string de save
			if(++it != animal_db.cend()) saveLine = saveLine + '\n';//adiciona um espaço ao final de todas as linhas menos a última.
	    	op << saveLine;
		}
	}catch(...){
		std::cout<<"Aviso: sem animais cadastrados no sistema" << std::endl;
	}
	op.close();
}

/**
 * Solicita dados ao usuário e adiciona um novo integrante ao sistema com base nos dados digitados
 * @Brief Verifica se há alguma incongruência ou erro de sintaxe antes de inicializar o novo membro
 */
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
				std::cout << "O cadastro só trabalha com numeros positivos"<<std::endl
						  << "o valor 0 está reservado para quando não há um funcionário para uma determinada função"<<std::endl;
				break;

		}
	}

}

/**
 * Solicita dados ao usuário e adiciona um novo integrante ao sistema com base nos dados digitados
 * @Brief Verifica se há alguma incongruência ou erro de sintaxe antes de inicializar o novo membro
 */
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

	try{
		//ID do animal
		std::cout<<"Digite o ID do novo animal"<<std::endl;
		std::cin>>anim_id;
		if(!std::cin){throw 11;}//input léxico em campo numerico
		if(anim_id<0){throw 12;}//input negativo, aceitar somente numeros naturais
		if(animal_db.find(anim_id) != animal_db.end()){throw 1;}//ERRO: ID em uso
		std::cin.ignore();//ignorar o a quebra de linha do cin

		//Tipo do animal
		std::cout<<"Digite a classe do novo animal"<<std::endl;
		std::getline(std::cin,anim_classe);
		if (  anim_classe!="Aves"
			&&anim_classe!="Amphibia"
			&&anim_classe!="Reptilia"
			&&anim_classe!="Mammalia"){throw 2;}//ERRO: Informação inválida dada como input


		//Nome do animal
		std::cout<<"Digite o nome da especie do novo animal"<<std::endl;
		std::getline(std::cin,anim_nome);
		if(anim_nome.size()==0){throw 3;}//ERRO: Campo obrigatorio não preenchido

		//Nome científico do animal
		std::cout<<"Digite o nome científico do novo animal"<<std::endl;
		std::getline(std::cin,anim_cientifico);
		if(anim_cientifico.size()==0){throw 4;}//ERRO: Campo obrigatorio não preenchido

		//Sexo do animal
		std::cout<<"Digite o sexo do novo animal"<<std::endl;
		std::cin>>anim_sexo;
		std::cin.ignore();//ignorar o a quebra de linha do cin
		if (anim_sexo!='M' && anim_sexo!='F'){throw 5;}//ERRO: input inválido

		//Tamanho do animal
		std::cout<<"Digite o tamanho do novo animal (em metros)"<<std::endl;
		std::cin>>anim_tamanho;
		std::cin.ignore();//ignorar o a quebra de linha do cin
		if(!std::cin){throw 11;}//input léxico em campo numerico
		if(anim_tamanho<=0){throw 12;}//input negativo, aceitar somente numeros reais positivos

		//Dieta do animal
		std::cout<<"Digite a dieta do novo animal"<<std::endl;
		std::getline(std::cin,anim_dieta);
		if(anim_dieta.size()==0){throw 6;}//ERRO: Campo obrigatorio não preenchido

		//ID do veterinário
		std::cout<<"Digite o ID do veterinário responsável pelo novo animal"<<std::endl;
		std::cin>>auxId;
		if(!std::cin){throw 11;}//input léxico em campo numerico
		if(auxId!=0 && funcionario_db.find(auxId) == funcionario_db.end()){throw 7;}//ERRO: Não há funcionário cadastrado com esse id
		if(auxId!=0 && funcionario_db[auxId]->getTipo_funcionario() != "Veterinario"){throw 8;}//ERRO: O funcionario não é veterinario
		  (auxId==0) ? anim_veterinario = nullptr : anim_veterinario = funcionario_db[auxId];//0 indica q n há funcionario cuidando daquele animal
		std::cin.ignore();//ignorar o a quebra de linha do cin

		//ID do tratador
		std::cout<<"Digite o ID do tratador responsável pelo novo animal"<<std::endl;
		std::cin>>auxId;
		if(!std::cin){throw 11;}//input léxico em campo numerico
		if(auxId!=0 && funcionario_db.find(auxId) == funcionario_db.end()){throw 7;}//ERRO: Não há funcionário cadastrado com esse id
		if(auxId!=0 && funcionario_db[auxId]->getTipo_funcionario() != "Tratador"){throw 9;}//ERRO: O funcionario não é tratador
		  (auxId==0) ? anim_veterinario = nullptr : anim_veterinario = funcionario_db[auxId];//0 indica q n há funcionario cuidando daquele animal
		anim_tratador = funcionario_db[auxId];
		std::cin.ignore();//ignorar o a quebra de linha do cin
		
		//Nome de batismo do animal
		std::cout<<"Digite o nome de batismo do novo animal"<<std::endl;
		std::getline(std::cin,anim_batismo);
		if (anim_batismo.size()==0){throw 10;}


		//INICIALIZA ANIMAL

		if(anim_classe=="Mammalia"){
			animal_db[anim_id] = std::make_shared<Mamifero>(
													Mamifero(anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
		}

		if(anim_classe=="Reptilia"){
			animal_db[anim_id] = std::make_shared<Reptil>(
													Reptil  (anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
		}

		if(anim_classe=="Amphibia"){
			animal_db[anim_id] = std::make_shared<Anfibio>(
													Anfibio (anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
		}

		if(anim_classe=="Aves"){
			animal_db[anim_id] = std::make_shared<Ave>(
													Ave     (anim_id, anim_classe, anim_nome
															,anim_cientifico,anim_sexo, anim_tamanho
															,anim_dieta, anim_veterinario, anim_tratador,anim_batismo));
		}

	}catch(int error_code){//lista de códigos de erro

		std::cout << "ERRO: ";
		switch(error_code)
		{
			case 1:
				std::cout << "o número "<< anim_id <<" já é o ID de outro animal"<<std::endl;
				break;
			case 2:
				std::cout << "o sistema só aceita estas classes: Aves, Amphibia, Reptilia e Mammalia"<<std::endl;
				break;
			case 3:
				std::cout << "o nome da especie é obrigatório para o cadastro"<<std::endl;
				break;
			case 4:
				std::cout << "o nome da científico é obrigatório para o cadastro"<<std::endl;
				break;
			case 5:
				std::cout << "insira um caractere válido para registrar o sexo do animal (M , F)"<<std::endl;
				std::cin.clear();
				break;
			case 6:
				std::cout << "informar a dieta do animal é obrigatória para o cadastro"<<std::endl;
				break;
			case 7:
				std::cout << "não há funcionário cadastrado com o ID "<< auxId <<std::endl;
				break;
			case 8:
				std::cout << "o funcionário cadastrado não é veterinário"<<std::endl;
				break;
			case 9:
				std::cout << "o funcionário cadastrado não é tratador"<<std::endl;
				break;
			case 10:
				std::cout << "o nome de batismo é obrigatório para o cadastro"<<std::endl;
				break;
			case 11:
				std::cout << "insira um número válido para prosseguir com o cadastro"<<std::endl;
				std::cin.clear();
				break;
			case 12:
				std::cout << "O cadastro só trabalha com numeros positivos"<<std::endl;
				break;

		}

	}

}

/**
 * Função auxiliar à removeFuncionario
 * @Brief desvincula animais do tratador a ser removidos para evitar erros
 * @Param ID do veterinario a ser removido
 */
void Loja::desvincularFuncionario(int func_id_remover){
	if(funcionario_db[func_id_remover]->getTipo_funcionario()=="Veterinario"){//como o tipo de funcionario é mutuamente excludente só se verifica um campo de todos os animais, funcionario ou tratador
		for(auto it = animal_db.cbegin(); it != animal_db.cend(); ++it){  //1. percorre o map que armazena os animais 
	    	if(it->second->getVeterinario()->getId() == func_id_remover){ //2. o valor second das células de animal_db armazena ponteiros para
	    		it->second->setVeterinario(nullptr);                        //animais, é solicitado um ponteiro ao seu tratador, e então o id
	    				                                                  //a esse ponteiro para ver se está sendo removido (e seta nullptr no animal)
	    	}                                                             //3. encerra o processo caso encontre o funcionario no primeiro campo	                                                          
		}
	}else if(funcionario_db[func_id_remover]->getTipo_funcionario()=="Tratador"){
		for(auto it = animal_db.cbegin(); it != animal_db.cend(); ++it){
	    	if(it->second->getTratador()->getId() == func_id_remover){    
	    		it->second->setTratador(nullptr);				 		      
	    	}	                                                          
		}
	}
}

/**
 * Pede ao usuário um ID e remove o membro com aquele ID
 * @Brief Verifica se há funcionário com o id antes de remover, e a validade do input
 */
void Loja::removerFuncionario(){
	int func_id;
	std::cout<<"Qual o id do funcionario que você gostaria de remover do registro? "<<std::endl;
	std::cin>>func_id;//valor a ser consultado
	try{
		if(func_id<=0){throw 1;}//verifica se o numero digitado é válido
		if(funcionario_db.find(func_id) == funcionario_db.end()){throw 2;}//verifica se há um funcionario com aquele id
		std::cout<<"Removendo "<<funcionario_db[func_id]->getNome()<<std::endl;//avisa o nome do funcionario
		desvincularFuncionario(func_id);//desvincula os animais do tratador a ser removido 
		funcionario_db.erase(func_id);//remove o funcionário do map
	}catch(int error_code){
		switch(error_code)
		{
			case 1:
				std::cout << "ID inválido" <<std::endl;
				break;
			case 2:
				std::cout << "o ID "<< func_id <<" não está associado a nenhum funcionário" <<std::endl;
				break;
		}
	}
}


/**
 * Pede ao usuário um ID e remove o membro com aquele ID
 * @Brief Verifica se há animal com o id antes de remover, e a validade do input
 */
void Loja::removerAnimal(){
	int anim_id;
	std::cout<<"Qual o id do animal que você gostaria de remover do registro? "<<std::endl;
	std::cin>>anim_id;//valor a ser consultado
	try{
		if(anim_id<0){throw 1;}
		if(animal_db.find(anim_id) == animal_db.end()){throw 2;}
		std::cout<<"Removendo "<<animal_db[anim_id]->getBatismo()<<std::endl;
		animal_db.erase(anim_id);
	}catch(int error_code){
		switch(error_code)
		{
			case 1:
				std::cout << "ID inválido" <<std::endl;
				break;
			case 2:
				std::cout << "o ID "<< anim_id <<" não está associado a nenhum animal" <<std::endl;
				break;
		}
	}
}


/**
 * Pede ao usuário um ID e mostra na tela o membro com aquele ID usando a sobrecarga de operador
 * @Brief Verifica se há funcionario com o id antes de remover, e a validade do input
 */
void Loja::func_imprimePorId(){
	std::cout << "Digite o ID do funcionario que deseja consultar" <<std::endl;
	int func_id;//valor a ser consultado
	std::cin>>func_id;
	try{
		if(!std::cin){throw 1;}
		if(func_id<0){throw 2;}
		if(funcionario_db.find(func_id) == funcionario_db.end()){throw 3;}
		std::cout<<*funcionario_db[func_id]<<std::endl;
	}catch(int error_code){
		switch(error_code)
		{
			case 1:
				std::cout << "O ID dos funcionários utiliza indexação numérica" <<std::endl;
				break;
			case 2:
				std::cout << "O número digitado é inválido" <<std::endl;
				break;
			case 3:
				std::cout << "o ID "<< func_id <<" não está associado a nenhum funcionário" <<std::endl;
				break;
		}

	}
}

/**
 * Pede ao usuário um ID e mostra na tela o membro com aquele ID usando a sobrecarga de operador
 * @Brief Verifica se há animal com o id antes de remover, e a validade do input
 */
void Loja::anim_imprimePorId(){
	std::cout << "Digite o ID do animal que deseja consultar" <<std::endl;
	int anim_id;//valor a ser consultado
	std::cin>>anim_id;
	try{
		if(!std::cin){throw 1;}
		if(anim_id<0){throw 2;}
		if(animal_db.find(anim_id) == animal_db.end()){throw 3;}
		std::cout<<*animal_db[anim_id]<<std::endl;
	}catch(int error_code){
		switch(error_code)
		{
			case 1:
				std::cout << "O ID dos animais utiliza indexação numérica" <<std::endl;
				break;
			case 2:
				std::cout << "O número digitado é inválido" <<std::endl;
				break;
			case 3:
				std::cout << "o ID "<< anim_id <<" não está associado a nenhum animal" <<std::endl;
				break;
		}

	}
}

/**
 * Via de interação com o usuário. Por meio desse console o usuário chama funções e realiza inputs
 * @Brief Faz uma sequência de testes de inputs e limpeza de CIN para evitar crashes, quando estes ocorrem ele mostra uma mensagem e fecha o programa
 */
void Loja::interface(){
	int opcao;
	bool sair = false;//comando para encerrar o loop no qua está o programa


	while(!sair){
		std::cout<<funcionario_db.size()<<std::endl;
		std::cout   <<"1. Ver as informações de um animal (por ID)"<<std::endl
					<<"2. Ver as informações de um funcionário (por ID)"<<std::endl
					<<"3. Cadastrar um animal"<<std::endl
					<<"4. Cadastrar um funcionário"<<std::endl
					<<"5. Remover um animal do cadastro"<<std::endl
					<<"6. Remover um funcionário do cadastro"<<std::endl
					<<"7. Listar todos os animais"<<std::endl
					<<"8. Listar todos os funcionários"<<std::endl
					<<"9. Sair"<<std::endl;
		try{

			//Usuário decide qual será o procedimento
			std::cin>>opcao;
			if(!std::cin){throw 1;}//input léxico em campo numerico
			if(opcao<1||opcao>9){throw 2;}//opção inválida

			//Execução do procedimento
			switch(opcao){
				case 1:
					Loja::anim_imprimePorId();						
					break;
				case 2:
					Loja::func_imprimePorId();
					break;
				case 3:
					Loja::adicionarAnimal();
					break;
				case 4:
					Loja::adicionarFuncionario();
					break;
				case 5:
					Loja::removerAnimal();
					break;
				case 6:
					Loja::removerFuncionario();
					break;
				case 7:
					animal_db.empty() == true ? throw 3 : Loja::exibirAnimais();
					break;
				case 8:
					funcionario_db.empty() == true ? throw 4 : Loja::exibirFuncionarios();
					break;
				case 9:
					sair = true;
					break;
			}
		}catch(int error_code){
			switch(error_code){
				case 1:
					std::cin.clear();
					std::cin.ignore();
					std::cout<<"Digite um número válido"<<std::endl;
					break;
				case 2:
					std::cout<<"Este código não está associado a nenhuma operação"<<std::endl;
					break;
				case 3:
					std::cout<<"Não há nenhum animal cadastrado"<<std::endl;
					break;
				case 4:
					std::cout<<"Não há nenhum funcionário cadastrado"<<std::endl;
					break;
				default:
				std::cin.clear();
				std::cin.ignore();
				sair = true;//impede que loops fora do escopo desse tratamento travem o programa
				std::cout<<"Erro Fatal: Encerrando programa"<<std::endl;
			}
		}
	}

}

//Carrega os bancos de dados e interface ao inicializar
Loja::Loja(){
	Loja::carregarFuncionarios();
	Loja::carregarAnimais();
	Loja::interface();
}
//Salva o estado atual ao sair
Loja::~Loja(){
	Loja::salvarFuncionarios();
	Loja::salvarAnimais();
}
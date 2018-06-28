#include <iostream>
#include <fstream>
#include <string> 

#include "../include/animal.h"
#include "../include/veterinario.h"
#include "../include/animal.h"

Animal::Animal(){

	//int temp_int; REATIVAR APOS CRIAR UMA CLASSE CONTAINER PARA OS _DB
	std::string temp;
	std::string::size_type sz; // alias do size_t de string

	std::ifstream ip("./data/animal_db.csv");
	
	if(!ip.is_open()){
		std::cout << "ERRO: arquivo animal_db.csv nao foi aberto"<<std::endl;
	}
	

	//ID
	getline(ip,temp,';');
	m_id = std::stoi(temp,&sz);//converte a string temp em int

	//CLASSE
	getline(ip,m_classe,';');

	//NOME (da especie)
	getline(ip,m_nome,';');

	//NOME CIENTIFICO
	getline(ip,m_cientifico,';');	

	//SEXO
	getline(ip,temp,';');
	m_sexo = *temp.c_str();//converte a string temp em char

	//TAMANHO
	getline(ip,temp,';');
	m_tamanho = ::atof(temp.c_str());//converte a string temp em float

	//DIETA
	getline(ip,m_dieta,';');

	//VETERINARIO
	getline(ip,temp,';');
	//temp_int = std::stoi(temp,&sz);
	//m_veterinario = animal_db[temp_int]; TODO: settar animal como friend do container com o map animal_db

	//VETERINARIO
	getline(ip,temp,';');
	//temp_int = std::stoi(temp,&sz);
	//m_tratador = animal_db[temp_int]; TODO: settar animal como friend do container com o map animal_db

	//BATISMO
	getline(ip,m_batismo,'\n');

}

Animal::~Animal(){}


//GETTERS/SETTERS
int Animal::getId(){return m_id;}
void Animal::setId(int id){m_id = id;}
std::string Animal::getClasse(){return m_classe;}
void Animal::setClasse(std::string classe){m_classe = classe;}
std::string Animal::getNome(){return m_nome;}
void Animal::setNome(std::string nome){m_nome = nome;}
std::string Animal::getCientifico(){return m_cientifico;}
void Animal::setCientifico(std::string cientifico){m_cientifico = cientifico;}
char Animal::getSexo(){return m_sexo;}
void Animal::setSexo(char sexo){m_sexo = sexo;}
float Animal::getTamanho(){return m_tamanho;}
void Animal::setTamanho(float tamanho){m_tamanho = tamanho;}
std::string Animal::getDieta(){return m_dieta;}
void Animal::setDieta(std::string dieta){m_dieta = dieta;}
std::string Animal::getBatismo(){return m_batismo;}
void Animal::setBatismo(std::string batismo){m_batismo = batismo;}
Veterinario Animal::getVeterinario(){return m_veterinario;}
void Animal::setVeterinario(Veterinario veterinario){m_veterinario = veterinario;}
Tratador Animal::getTratador(){return m_tratador;}
void Animal::setTratador(Tratador tratador){m_tratador = tratador;}


std::ostream& operator<<(std::ostream& os, const Animal& animal){
	os<<"ID: "<< animal.m_id << std::endl
	  <<"Classe: "<< animal.m_classe << std::endl
	  <<"Espécie: "<< animal.m_nome << std::endl
	  <<"Nome cientifico: "<< animal.m_cientifico << std::endl
	  <<"Sexo: "<< animal.m_sexo << std::endl
	  <<"Tamanho: "<< animal.m_tamanho << std::endl
	  <<"Dieta: "<< animal.m_dieta << std::endl
	  //<<"Veterinario: "<< animal.m_veterinario.getNome() << std::endl
	  //<<"Tratador: "<< animal.m_tratador.getNome() << std::endl
	  <<"Nome de batismo: "<< animal.m_batismo << std::endl;

	return os;
}
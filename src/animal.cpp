#include <iostream>
#include <fstream>
#include <string> 

#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/animal.h"

Animal::Animal(){
	std::string converter;
	std::string::size_type sz; // alias do size_t de string

	std::ifstream ip("./data/animal_db.csv");

	if(ip.is_open()){
		std::cout << "arquivo animal_db.csv aberto, feche-o para completar a operacao"<<std::endl;
	}
	getline(ip,converter,';');
	std::cout<<converter<<std::endl;
	m_id = std::stoi(converter,&sz);
	std::cout<<m_id<<std::endl;

}
Animal::~Animal(){}
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
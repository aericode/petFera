#include <iostream>
#include <fstream>
#include <string> 
#include <memory>

#include "../include/tratador.h"
#include "../include/veterinario.h"
#include "../include/animal.h"

Animal::Animal  (){};

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
std::shared_ptr<Funcionario> Animal::getVeterinario(){return m_veterinario;}
void Animal::setVeterinario(std::shared_ptr<Funcionario> veterinario){m_veterinario = veterinario;}
std::shared_ptr<Funcionario> Animal::getTratador(){return m_tratador;}
void Animal::setTratador(std::shared_ptr<Funcionario> tratador){m_tratador = tratador;}

std::string Animal::emiteSave(){
	std::string dataSave; //string a ser retornada, informações são adicionadas por meio de concatenação (sobrecarga do + na string)
	std::string separador = ";";//escolhe separador (leitura funciona somente com ; de acordo com o solicitado)
	/*
	std::string veterinario_id;
	std::string tratador_id;

	if(m_veterinario==nullptr){
		veterinario_id="0";
	}else{
		veterinario_id=std::to_string(m_veterinario->getId());
	}

	if(m_tratador==nullptr){
		tratador_id="0";
	}else{
		tratador_id=std::to_string(m_tratador->getId());
	}
	*/

	dataSave = std::to_string(m_id)                  + separador
			 + m_classe                              + separador
			 + m_nome                                + separador
			 + m_cientifico                          + separador
			 + m_sexo                                + separador
			 + std::to_string(m_tamanho)             + separador
			 + m_dieta                               + separador
			 + std::to_string(m_veterinario->getId())+ separador
			 + std::to_string(m_tratador->getId())   + separador
			 + m_batismo;

	return dataSave;
}


std::ostream& operator<<(std::ostream& os, const Animal& animal){
  os<<"ID: "<< animal.m_id << std::endl
	<<"Classe: "<< animal.m_classe << std::endl
	<<"Espécie: "<< animal.m_nome << std::endl
	<<"Nome cientifico: "<< animal.m_cientifico << std::endl
	<<"Sexo: "<< animal.m_sexo << std::endl
	<<"Tamanho: "<< animal.m_tamanho << std::endl
	<<"Dieta: "<< animal.m_dieta << std::endl;

	if(animal.m_veterinario!=nullptr){
		os<<"Veterinario: "<< animal.m_veterinario->getNome() << std::endl;
	}else{ 
		os<<"Veterinario: Não definido" << std::endl;
	}

	if(animal.m_veterinario!=nullptr){
		os<<"Tratador: "<< animal.m_tratador->getNome() << std::endl;
	}else{ 
	 	os<<"Tratador: Não definido" << std::endl;
	}

	os<<"Nome de batismo: "<< animal.m_batismo << std::endl;

	return os;
}
#include <iostream>
#include <fstream>
#include <string> 
#include <memory>

#include "../include/tratador.h"
#include "../include/veterinario.h"
#include "../include/animal.h"

Animal::Animal  (int anim_id, std::string anim_classe, std::string anim_nome
				,std::string anim_cientifico,char anim_sexo,float anim_tamanho
				,std::string anim_dieta, std::shared_ptr<Funcionario> anim_veterinario
				,std::shared_ptr<Funcionario> anim_tratador,std::string anim_batismo){ 
																				m_id = anim_id;
																				m_classe = anim_classe;
																				m_nome = anim_nome;
																				m_cientifico = anim_cientifico;
																				m_sexo = anim_sexo;
																				m_tamanho = anim_tamanho;
																				m_dieta = anim_dieta;
																				m_veterinario = anim_veterinario;
																				m_tratador = anim_tratador;
																				m_batismo = anim_batismo;}

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
//std::shared_ptr<Veterinario> Animal::getVeterinario(){return m_veterinario;}
//void Animal::setVeterinario(std::shared_ptr<Veterinario> veterinario){m_veterinario = veterinario;}
//std::shared_ptr<Tratador> Animal::getTratador(){return m_tratador;}
//void Animal::setTratador(std::shared_ptr<Tratador> tratador){m_tratador = tratador;}


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
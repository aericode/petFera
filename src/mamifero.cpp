/**
  * @file 		mamifero.cpp
  * @brief 		construtor, e getters-setters específicos
  * @details 	estabelece funções diferenciadas da subclasse mamifero
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */
#include <string> 
#include "../include/mamifero.h"

std::string Mamifero::getCor_pelo(){return m_cor_pelo;}
void Mamifero::setCor_pelo(std::string cor_pelo){m_cor_pelo = cor_pelo;}

Mamifero::Mamifero(int anim_id, std::string anim_classe, std::string anim_nome
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
Mamifero::~Mamifero(){}
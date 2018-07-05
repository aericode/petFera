/**
  * @file 		anfíbio.cpp
  * @brief 		construtor, e getters-setters específicos
  * @details 	estabelece funções diferenciadas da subclasse anfíbio
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */
#include "../include/anfibio.h"
#include <string>

int Anfibio::getTotal_mudas(){return m_total_mudas;}
void Anfibio::setTotal_mudas(int total_mudas){m_total_mudas = total_mudas;}
std::string Anfibio::getUltima_muda(){return m_ultima_muda;}
void Anfibio::setUltima_muda(std::string ultima_muda){m_ultima_muda = ultima_muda;}

Anfibio::Anfibio(int anim_id, std::string anim_classe, std::string anim_nome
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
Anfibio::~Anfibio(){}
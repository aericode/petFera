#include "../include/ave.h"
#include <string>

int Ave::getTamanho_bico(){return m_tamanho_bico;}
void Ave::setTamanho_bico(int tamanho_bico){m_tamanho_bico = tamanho_bico;}
int Ave::getEnvergadura(){return m_envergadura;}
void Ave::setEnvergadura(int envergadura){m_envergadura = envergadura;}

Ave::Ave        (int anim_id, std::string anim_classe, std::string anim_nome
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
Ave::~Ave(){};
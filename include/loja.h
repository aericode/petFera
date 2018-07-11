#ifndef LOJA_H
#define LOJA_H


#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"
#include "animal.h"
#include "reptil.h"
#include "anfibio.h"
#include "mamifero.h"
#include "animalSilvestre.h"
#include "exotico.h"
#include "nativo.h"
#include "aveExotica.h"
#include "aveNativa.h"

class Loja
{
private:
	std::map<int, std::shared_ptr <Animal> > animal_db;
	std::map<int, std::shared_ptr <Funcionario> > funcionario_db;
public:
	Loja();
	~Loja();
	void carregarFuncionarios();
	void carregarAnimais();
	void salvarFuncionarios();
	void exibirFuncionarios();
	void salvarAnimais();
	void exibirAnimais();
	void func_imprimePorId();
	void anim_imprimePorId();
	void adicionarFuncionario();
	void adicionarAnimal();
	void removerFuncionario();
	void removerAnimal();

	void interface();
	std::map<int, std::shared_ptr <Animal> > getAnimalDatabase();
};



#endif
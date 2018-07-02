#ifndef LOJA_H
#define LOJA_H


#include <iostream>
#include <string>
#include <memory>
#include <map>

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
	void func_imprimePorId(int);
	void anim_imprimePorId(int);
};



#endif
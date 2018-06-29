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
	map<int, std::shared_ptr <Animal> > animal_db;
	map<int, std::shared_ptr <Funcionario> > funcionario_db;
public:
	void carregarFuncionarios();
	void carregarAnimais();
};



#endif
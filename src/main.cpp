#include <iostream>
#include <string>

#include "../include/funcionario.h"
#include "../include/veterinario.h"
#include "../include/tratador.h"
#include "../include/animal.h"

int main(){

	Animal ferinha;

	ferinha.setNome("Gatimon");
	std::cout<<ferinha.getNome()<<std::endl;

    return 0;
}

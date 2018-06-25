#include <iostream>
#include <string>

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

int main(){

	Animal ferinha;
	Exotico fera;
	Veterinario vet1;
	Tratador trat1;

	vet1.setNome("Adalberto");
	trat1.setNome("Felisberto");
	
	
	ferinha.setBatismo("Gatimon");
	std::cout<<ferinha.getBatismo()<<std::endl;
	ferinha.setClasse("Mamifero");
	std::cout<<ferinha.getClasse()<<std::endl;
	ferinha.setCientifico("Felis catus");
	std::cout<<ferinha.getCientifico()<<std::endl;
	ferinha.setSexo('F');
	std::cout<<ferinha.getSexo()<<std::endl;
	ferinha.setTamanho(0.89);
	std::cout<<ferinha.getTamanho()<<std::endl;
	ferinha.setDieta("Whiskas sachê");
	std::cout<<ferinha.getDieta()<<std::endl;
	ferinha.setNome("Gato");
	std::cout<<ferinha.getNome()<<std::endl;
	ferinha.setVeterinario(vet1);
	ferinha.setTratador(trat1);
	
	Veterinario aux1 = ferinha.getVeterinario();
	Tratador aux2 = ferinha.getTratador();

	std::cout<<aux1.getNome()<<std::endl;
	std::cout<<aux2.getNome()<<std::endl;
	

	fera.setIbama("12345");
	std::cout<<fera.getIbama()<<std::endl;

    return 0;
}

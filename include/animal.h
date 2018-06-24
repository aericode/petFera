#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
protected:
	int id;
	std::string classe;
	std::string nome; //especie do animal
	std::string cientifico;
	char sexo;
	float tamanho;
	std::string dieta;
	Veterinario veterinario;
	Tratador tratador;
	std::string batismo;

};



#endif
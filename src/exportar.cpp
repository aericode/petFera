#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include </home/eric/Faculdade/LP/Projetos/petFera/include/loja.h>


int main (int argc, char** argv){

	Loja loja;//9 ao inicializar

	std::string outputLocation = argv[argc - 1];
	std::ofstream op;

	std::string classKey;
	std::string veterinarioKey;
	std::string tratadorKey;

	std::string classFlag       = "-c";
	std::string veterinarioFlag = "-v";
	std::string tratadorFlag    = "-t";
	
	for (int i = 0; i < (argc-1); i++){
		if(argv[i]==       classFlag){classKey = argv[i+1];}
		if(argv[i]== veterinarioFlag){veterinarioKey = argv[i+1];}
		if(argv[i]==    tratadorFlag){tratadorKey = argv[i+1];}
	}

	//map dos animais
	std::map<int, std::shared_ptr<Animal> > animal_db = loja.getAnimalDatabase();
	op.open(outputLocation);

	//usa o getter do animal para pegar a informação a ser verificada
	for(auto it = animal_db.cbegin(); it != animal_db.cend(); ++it){

    	if(classKey == it->second->getClasse()
    	or veterinarioKey == it->second->getVeterinario()->getNome()
    	or tratadorKey == it->second->getTratador()->getNome()){
    		if(it!=animal_db.cbegin())op<<'\n';//emitesave não coloca espaços, isso evita erros no loading
    		op<<it->second->emiteSave();
    	}
	}
	
	op.close();

	return 0;
}
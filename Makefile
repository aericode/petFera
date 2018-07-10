INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

CC = g++
CFLAGS =  -Wall -std=c++11 -I$(INC_DIR)
ARCHIVE = ar

linux: petlib.so petfera

petlib.so:  $(SRC_DIR)/animal.cpp  $(SRC_DIR)/anfibio.cpp  $(SRC_DIR)/mamifero.cpp  $(SRC_DIR)/ave.cpp  $(SRC_DIR)/reptil.cpp  $(SRC_DIR)/funcionario.cpp  $(SRC_DIR)/veterinario.cpp  $(SRC_DIR)/tratador.cpp  $(SRC_DIR)/animalSilvestre.cpp  $(SRC_DIR)/exotico.cpp  $(SRC_DIR)/aveExotica.cpp  $(SRC_DIR)/aveNativa.cpp  $(SRC_DIR)/loja.cpp  $(SRC_DIR)/nativo.cpp
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/animal.cpp -o $(OBJ_DIR)/animal.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/anfibio.cpp -o $(OBJ_DIR)/anfibio.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/mamifero.cpp -o $(OBJ_DIR)/mamifero.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/ave.cpp -o $(OBJ_DIR)/ave.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/reptil.cpp -o $(OBJ_DIR)/reptil.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/funcionario.cpp -o $(OBJ_DIR)/funcionario.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/veterinario.cpp -o $(OBJ_DIR)/veterinario.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/tratador.cpp -o $(OBJ_DIR)/tratador.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/animalSilvestre.cpp -o $(OBJ_DIR)/animalSilvestre.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/exotico.cpp -o $(OBJ_DIR)/exotico.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/aveExotica.cpp -o $(OBJ_DIR)/aveExotica.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/aveNativa.cpp -o $(OBJ_DIR)/aveNativa.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/loja.cpp -o $(OBJ_DIR)/loja.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/nativo.cpp -o $(OBJ_DIR)/nativo.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/animal.o $(OBJ_DIR)/anfibio.o $(OBJ_DIR)/mamifero.o $(OBJ_DIR)/ave.o $(OBJ_DIR)/reptil.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/veterinario.o $(OBJ_DIR)/tratador.o $(OBJ_DIR)/animalSilvestre.o $(OBJ_DIR)/exotico.o $(OBJ_DIR)/aveExotica.o $(OBJ_DIR)/aveNativa.o $(OBJ_DIR)/loja.o $(OBJ_DIR)/nativo.o
	@echo "+++[Biblioteca dinamica criada em $(LIB_DIR)/$@]+++"

petfera:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/petlib.so -o $(BIN_DIR)/$@

clean:
	@echo "Removendo arquivos objeto e binarios"
	@rm -rf $(OBJ_DIR)/*
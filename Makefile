all: myProgram

myProgram: main.o libmylib.a
		g++ -lm -o myProgram main.o -L. -lmylib

main.o: src/main.cpp
		g++ -O -c src/main.cpp -I.

anfibio.o: src/anfibio.cpp include/anfibio.h
		g++ -O -c src/anfibio.cpp -I.

animal.o: src/animal.cpp include/animal.h
		g++ -O -c src/animal.cpp -I.

animalSilvestre.o: src/animalSilvestre.cpp include/animalSilvestre.h
		g++ -O -c src/animalSilvestre.cpp -I.

ave.o: src/ave.cpp include/ave.h
		g++ -O -c src/ave.cpp -I.

aveExotica.o: src/aveExotica.cpp include/aveExotica.h
		g++ -O -c src/aveExotica.cpp -I.

aveNativa.o: src/aveNativa.cpp include/aveNativa.h
		g++ -O -c src/aveNativa.cpp -I.

exotico.o: src/exotico.cpp include/exotico.h
		g++ -O -c src/exotico.cpp -I.

funcionario.o: src/funcionario.cpp include/funcionario.h
		g++ -O -c src/funcionario.cpp -I.

loja.o: src/loja.cpp include/loja.h
		g++ -O -c src/loja.cpp -I.

mamifero.o: src/mamifero.cpp include/mamifero.h
		g++ -O -c src/mamifero.cpp -I.

nativo.o: src/nativo.cpp include/nativo.h
		g++ -O -c src/nativo.cpp -I.

reptil.o: src/reptil.cpp include/reptil.h
		g++ -O -c src/reptil.cpp -I.

tratador.o: src/tratador.cpp include/tratador.h
		g++ -O -c src/tratador.cpp -I.

veterinario.o: src/veterinario.cpp include/veterinario.h
		g++ -O -c src/veterinario.cpp -I.

libmylib.a: anfibio.o animal.o animalSilvestre.o ave.o aveExotica.o aveNativa.o exotico.o funcionario.o loja.o mamifero.o nativo.o reptil.o tratador.o veterinario.o
		ar rcs libmylib.a anfibio.o animal.o animalSilvestre.o ave.o aveExotica.o aveNativa.o exotico.o funcionario.o loja.o mamifero.o nativo.o reptil.o tratador.o veterinario.o

libs: libmylib.a

clean:
		rm -f myProgram *.o *.a *.gch 
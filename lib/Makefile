all: myProgram

myProgram: obj/main.o libs/libmylib.a #libmylib.a is the dependency for the executable
	gcc -lm -o myProgram obj/main.o -L. -lmylib

obj/main.o: src/main.cpp
	-c $@ -Wall -Werror -fpic src/main.cpp

#lib

obj/animal.o: src/animal.cpp
	gcc -c $@ -Wall -Werror -fpic src/animal.cpp -Iinclude

obj/anfibio.o: src/anfibio.cpp
	gcc -c $@ -Wall -Werror -fpic src/anfibio.cpp -Iinclude

obj/mamifero.o: src/mamifero.cpp
	gcc -c $@ -Wall -Werror -fpic src/mamifero.cpp -Iinclude

obj/ave.o: src/ave.cpp
	gcc -c $@ -Wall -Werror -fpic src/ave.cpp -Iinclude

obj/reptil.o: src/reptil.cpp
	gcc -c $@ -Wall -Werror -fpic src/reptil.cpp -Iinclude

obj/funcionario.o: src/funcionario.cpp
	gcc -c $@ -Wall -Werror -fpic src/funcionario.cpp -Iinclude

obj/veterinario.o: src/veterinario.cpp
	gcc -c $@ -Wall -Werror -fpic src/veterinario.cpp -Iinclude

obj/tratador.o: src/tratador.cpp
	gcc -c $@ -Wall -Werror -fpic src/tratador.cpp -Iinclude

obj/animalSilvestre.o: src/animalSilvestre.cpp
	gcc -c $@ -Wall -Werror -fpic src/animalSilvestre.cpp -Iinclude

obj/exotico.o: src/exotico.cpp
	gcc -c $@ -Wall -Werror -fpic src/exotico.cpp -Iinclude

obj/aveExotica.o: src/aveExotica.cpp
	gcc -c $@ -Wall -Werror -fpic src/aveExotica.cpp -Iinclude

obj/aveNativa.o: src/aveNativa.cpp
	gcc -c $@ -Wall -Werror -fpic src/aveNativa.cpp -Iinclude

obj/loja.o: src/loja.cpp
	gcc -c $@ -Wall -Werror -fpic src/loja.cpp -Iinclude

obj/nativo.o: src/nativo.cpp
	gcc -c $@ -Wall -Werror -fpic src/nativo.cpp -Iinclude

libs/libmylib.a: obj/animal.o obj/anfibio.o obj/mamifero.o obj/ave.o obj/reptil.o obj/funcionario.o obj/veterinario.o obj/tratador.o obj/animalSilvestre.o obj/exotico.o obj/aveExotica.o obj/aveNativa.o obj/loja.o obj/nativo.o
	gcc -shared -o lib/libmylib.so obj/animal.o obj/anfibio.o obj/mamifero.o obj/ave.o obj/reptil.o obj/funcionario.o obj/veterinario.o obj/tratador.o obj/animalSilvestre.o obj/exotico.o obj/aveExotica.o obj/aveNativa.o obj/loja.o obj/nativo.o


libs: libs/libmylib.a

clean:
		rm -f myProgram *.o *.a *.gch 
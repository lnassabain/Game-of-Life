main: src/main.o src/grille.o src/io.o src/jeu.o
	gcc src/main.o src/grille.o src/io.o src/jeu.o -o main

main.o: src/main.c src/grille.h src/io.h src/jeu.h
	gcc -c src/main.c	
	
grille.o: src/grille.c src/grille.h 
	gcc -c src/grille.c
	
io.o: src/io.c src/io.h
	gcc -c src/io.c
	
jeu.o: src/jeu.c src/jeu.h
	gcc -c src/jeu.c

clean: 
	rm src/*.o main

dist: 
	tar cfJ NassabainLeonardo-GoL-v2.0.tar.xz src/*.c src/*.h makefile Doxyfile
	 
	
	

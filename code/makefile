OBJETS= main.o grille.o io.o jeu.o 
vpath %.h include
vpath %.c src
vpath %.o obj
OBJDIR=obj/
INCLUDE=include/
EXEC=bin/

main: main.o grille.o io.o jeu.o
	gcc $(OBJDIR)*.o -o $(EXEC)$@

main.o: main.c io.h jeu.h grille.h 
	gcc -c $< -o $(OBJDIR)$@

%.o : src/%.c $(INCLUDE)%.h
	gcc -c $< -o $(OBJDIR)$@	

clean: 
	rm $(OBJDIR)*.o $(EXEC)main

dist: 
	tar cfJ NassabainLeonardo-GoL-v2.0.tar.xz src/*.c include/*.h makefile doc/Doxyfile
	 
	
	

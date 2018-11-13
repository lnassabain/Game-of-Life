OBJETS= main.o grille.o io.o jeu.o 
vpath %.h include
vpath %.c src
vpath %.o obj
OBJDIR=obj/
INCLUDE=include/
SRCDIR= src/
EXEC=bin/

main: $(OBJETS)
	gcc $(OBJDIR)*.o -o $(EXEC)$@

main.o: main.c $(INCLUDE)*.h 
	gcc -c $< -o $(OBJDIR)$@

%.o : src/%.c $(INCLUDE)%.h
	gcc -c $< -o $(OBJDIR)$@	

clean: 
	rm $(OBJDIR)*.o $(EXEC)main

dist: 
	tar cfJ NassabainLeonardo-GoL-v2.0.tar.xz $(SRCDIR)*.c $(INCLUDE)*.h makefile doc/Doxyfile
	 
	
	

CC= gcc -c
CCO= gcc -o
OBJETS= main.o grille.o io.o jeu.o 
vpath %.h include
vpath %.c src
vpath %.o obj
OBJDIR=obj/
INCLUDE=include/
SRCDIR= src/
EXEC=bin/

main: $(OBJETS)
	$(CCO) $(EXEC)$@ $(OBJDIR)*.o

main.o: main.c $(INCLUDE)*.h 
	$(CC) $< -o $(OBJDIR)$@

%.o : src/%.c $(INCLUDE)%.h
	$(CC) $< -o $(OBJDIR)$@	

clean: 
	rm $(OBJDIR)*.o $(EXEC)main

dist: 
	tar cfJ NassabainLeonardo-GoL-v2.0.tar.xz $(SRCDIR)*.c $(INCLUDE)*.h makefile doc/Doxyfile
	
	

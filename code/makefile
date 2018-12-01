ifeq ($(MODE), TEXTE)

CC= gcc -Iinclude -c
CCO= gcc -o
OBJETS= main.o grille.o io.o jeu.o
HEAD = grille.h io.h jeu.h 
vpath %.h include
vpath %.c src
vpath %.o obj
OBJDIR=obj/
INCLUDE=include/
SRCDIR= src/
EXEC=bin/

main: $(OBJETS)
	$(CCO) $(EXEC)$@ $(OBJDIR)main.o $(OBJDIR)grille.o $(OBJDIR)io.o $(OBJDIR)jeu.o
	@echo "-----All files are up to date, normal exec file availible-----"

main.o: main.c $(HEAD) 
	$(CC) $< -o $(OBJDIR)$@

%.o : %.c %.h
	$(CC) $< -o $(OBJDIR)$@	

clean: 
	rm $(OBJDIR)*.o $(EXEC)main
	@echo "-----obj folder empty, main removed-----"

dist: 
	tar cfJ archive.tar.xz $(SRCDIR)*.c $(INCLUDE)*.h makefile doc/Doxyfile

else 

CC= gcc -Iinclude -c 
CCO = gcc -o
IPATH= -Iinclude
SRC= src/
OBJDIR= obj/
EXEC= bin/
OBJETS= cairo_main.o cairo_io.o grille.o jeu.o
HEAD= cairo_io.h grille.h jeu.h
vpath %.h include
vpath %.c src
vpath %.o obj

cmain: $(OBJETS)
	$(CCO) $(EXEC)$@ $(OBJDIR)cairo_main.o $(OBJDIR)cairo_io.o $(OBJDIR)grille.o $(OBJDIR)jeu.o -lcairo -lm -lX11
	@echo "-----All files are up to date, cairo exec file availible-----"

cairo_main.o: cairo_main.c $(HEAD)
	$(CC) $< -o $(OBJDIR)$@

%.o: %.c %.h
	$(CC) $< -o $(OBJDIR)$@

clean:
	rm $(EXEC)cmain $(OBJDIR)*.o
	@echo "-----obj folder empty, cmain removed-----"	

endif
	

ifeq ($(MODE), TEXTE)

CC= gcc -Iinclude -c
CCO= gcc -o
OBJETS= main.o io.o grille.o jeu.o 
HEAD = grille.h io.h jeu.h 
vpath %.h include
vpath %.c src
vpath %.o obj
vpath %.a lib
OBJDIR=obj/
INCLUDE=include/
SRCDIR= src/
EXEC=bin/
LIBDIR= lib/

main: $(OBJETS) libjeu.a
	$(CCO) $(EXEC)$@ $(OBJDIR)main.o $(OBJDIR)io.o -Llib -ljeu
	@echo "-----All files are up to date, normal exec file availible-----"

main.o: main.c $(HEAD) 
	$(CC) $< -o $(OBJDIR)$@

%.o : %.c %.h
	$(CC) $< -o $(OBJDIR)$@	

libjeu.a: grille.o jeu.o
	ar -crv $(LIBDIR)$@ $(OBJDIR)grille.o $(OBJDIR)jeu.o 

clean: 
	rm $(OBJDIR)*.o $(EXEC)main $(LIBDIR)*.a
	@echo "-----obj & lib folders empty, main removed-----"

dist: 
	tar cfJ NassabainLeonardo-GoL-v5.0.tar.xz $(SRCDIR)*.c $(INCLUDE)*.h makefile doc/Doxyfile

else 

CC= gcc -g -Iinclude -c 
CCO = gcc -g -o
IPATH= -Iinclude
SRCDIR= src/
OBJDIR= obj/
EXEC= bin/
LIBDIR= lib/
INCLUDE= include/
OBJETS= cairo_main.o cairo_io.o grille.o jeu.o
HEAD= cairo_io.h grille.h jeu.h
vpath %.h include
vpath %.c src
vpath %.o obj
vpath %.a lib

cmain: $(OBJETS) libjeu.a
	$(CCO) $(EXEC)$@ $(OBJDIR)cairo_main.o $(OBJDIR)cairo_io.o -Llib -ljeu -lcairo -lm -lX11
	@echo "-----All files are up to date, cairo exec file availible-----"

cairo_main.o: cairo_main.c $(HEAD)
	$(CC) $< -o $(OBJDIR)$@

%.o: %.c %.h
	$(CC) $< -o $(OBJDIR)$@

libjeu.a: grille.o jeu.o
	ar -crv $(LIBDIR)$@ $(OBJDIR)grille.o $(OBJDIR)jeu.o

clean:
	rm $(EXEC)cmain $(OBJDIR)*.o $(LIBDIR)*.a
	@echo "-----obj & lib folders empty, cmain removed-----"

dist:
	tar cfJ NassabainLeonardo-GoL-v5.0.tar.xz $(SRCDIR)*.c $(INCLUDE)*.h makefile doc/Doxyfile	

endif
	

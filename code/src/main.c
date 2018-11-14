#include <stdio.h>

#include "../include/grille.h"
#include "../include/io.h"
#include "../include/jeu.h"

int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}
	
	
	grille g, gc;
	compte_voisins_vivants = compte_vv_cyclique;
	vieillissement = 0;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	affiche_temps(0);
	affiche_grille(g);
	debut_jeu(&g, &gc);
	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}

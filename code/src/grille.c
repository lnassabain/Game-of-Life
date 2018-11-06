/**
  * \file grille.c
  * \brief Fonctions traitant les grilles
  * \date 06.Novembre.2018
  */

#include "grille.h"

/**
  * \fn void alloue_grille(int l, int c, grille* g)
  * \brief alloue une grille de taille l*c, et initialise toutes les cellules à mortes
  * \param l entier désignant le nombre de lignes, c désignant le nombre de colonnes et g l'adresse
  * de la grille qu'on alloue et initialise.
  * \return void, la fonction ne renvoie rien mais g est maintenant l'adresse d'une grille alloué et
  * initialisée.
  */

void alloue_grille (int l, int c, grille* g){
	g -> nbl = l;
	g -> nbc = c;
	g -> cellules = (int**) malloc (c * sizeof(int*));
	int i,j = 0;
	for (i = 0; i < c; i++) {
		g -> cellules[i] = (int*) malloc (l * sizeof(int));
	}
 	for (i = 0; i < c; i++) {
		for (j = 0; j< l ; j++){
			g -> cellules[i][j]= 0;
		}
	}
}


/**
  * \fn void libere_grille (grille* g)
  * \brief fonction qui libére (free) une grille allouée
  * \param g pointeur(adresse) vers une grille alloué
  * \return void, la fonction ne renvoie rien mais g est maintenant un pointeur vers une grille 
  * vide(ne contient pas de cellules)
  */

void libere_grille (grille* g){
	int i = 0;
	 for (i = 0; i < g -> nbc; i++){
		free (g -> cellules[i]);
	}
	free (g -> cellules);
}

/**
  * \fn init_grille_from_file (char* filename, grille* g)
  * \brief alloue et initialise la grille g à partir d'un fichier 
  * \param filename tableau(chaine) de caractères désignant le nom du fichier dans 
  * lequel se situe la grille à initialiser et allouer
  * \param g pointeur vers une grille qu'on va allouer et initialiser à partir du fichier rentré en 
  * parametres
  * \return void la fonction ne renvoie rien mais à la sortie de la fonction, g est un pointeur 
  * vers la grille dont la description se situait dans le fichier 
  */

void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);
	
	int i,j,n,l,c,vivantes=0;
	
	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);
	
	alloue_grille(l,c,g);
	
	fscanf(pfile, "%d", & vivantes);
	for (n=0; n< vivantes; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}
	
	fclose (pfile);
	return;
}

/**
  * \fn void copie_grille (grille gs, grille gd)
  * \brief la fonction recopiera la grille gs dans la grille gd 
  * \param gs grille à recopier
  * \param gd grille dans laquelle on recopiera la grille gs 
  * \return void, à la sortie de la fonction, la grille gd sera la même que la grille gs
  */
void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;	
}

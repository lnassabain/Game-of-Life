#include "../include/io.h"

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne_sans_age (int c, int* ligne){
	int i;
	for (i=0; i<c; ++i) 
		if (ligne[i] == 0 ) printf ("|   "); else printf ("| O ");
	printf("|\n");
	return;
}

void affiche_ligne_age (int c, int * ligne){
	int j;
	for (j=0; j<c; j++)
	{
		if (ligne[j]==0) printf ("|   ");
		else printf("| %d ", ligne[j]);
	}
	printf ("|\n");
	return;
}

void affiche_grille (grille g){	
	int i, l=g.nbl, c=g.nbc;
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}

void efface_grille (grille g){
	printf("\n\e[%dA",g.nbl*2 + 5); 
}

void affiche_temps (int tps){
	printf("Temps = %d", tps);
}

void efface_temps() {
	printf("\n\e[1A");
}

void debut_jeu(grille *g, grille *gc){
	char c = getchar(); 
	int tps = 0;
	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) {
			case '\n' : 
			{ // touche "entree" pour évoluer
				
				efface_grille(*g);
				efface_temps();
				affiche_temps (tps);
				affiche_grille(*g);
				evolue(g,gc);
				tps++;
				break;
			}

			case 'n' :
			{//touche n pour entrer au clavir le nom d'une nouvelle grille
				
				printf ("Entrez le nom de la nouvelle grille: \n");
				char nom_grille[300];
				grille g1, g2;
				tps = 0;
				scanf ("%s", nom_grille);
				init_grille_from_file (nom_grille, &g1);
				alloue_grille(g1.nbl, g1.nbc, &g2);
				printf("\n"); 
				affiche_temps (tps);
				affiche_grille (g1); 
				g = &g1;
				gc = &g2;
				break;
			}
	
			case 'v' :
			{//touche pour activer/désactiver le vieillissement des cellules
				if (affiche_ligne == affiche_ligne_sans_age) affiche_ligne = affiche_ligne_age;
				else if (affiche_ligne == affiche_ligne_age) affiche_ligne = affiche_ligne_sans_age;
				break;
			}

			case 'c' :
			{ //touche c pour activer/désactiver le voisinage cyclique
				if (compte_voisins_vivants == compte_vv_cyclique)
				{
					compte_voisins_vivants = compte_vv_non_cyclique;
				}
				else 
				{
					compte_voisins_vivants = compte_vv_cyclique;
  				}
				break;
			}
				

			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}

#include "../include/io.h"

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}


void affiche_ligne (int c, int * ligne){
	int j;
	for (j=0; j<c; j++)
	{
		if (ligne[j]==0) printf ("|   ");
		else if (ligne[j] ==-1) printf ("| X ");
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

void affiche_mode (int tps){
	printf("Temps = %d\n", tps);
	printf("Cyclique : %d\n", (compte_voisins_vivants == compte_vv_cyclique));
	printf("Vieillissement : %d", (vieillissement == 1));
}

void efface_mode() {
	printf("\n\e[3A");
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
				efface_mode();
				affiche_mode (tps);
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
				affiche_mode (tps);
				affiche_grille (g1); 
				g = &g1;
				gc = &g2;
				break;
			}
	
			case 'v' :
			{//touche pour activer/désactiver le vieillissement des cellules
				if (vieillissement==0) vieillissement=1;
				else if (vieillissement == 1) vieillissement=0; 
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

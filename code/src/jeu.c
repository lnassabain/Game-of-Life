#include "../include/jeu.h"

int compte_vv_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v; 
}

int compte_vv_non_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(i-1, j-1, g);
	v+= est_vivante(i-1, j, g);
	v+= est_vivante(i-1, j+1, g);
	v+= est_vivante(i, j-1, g);
	v+= est_vivante(i, j+1, g);
	v+= est_vivante(i+1, j-1, g);	
	v+= est_vivante(i+1, j, g);
	v+= est_vivante(i+1, j+1, g);

	return v;
}



void evolue (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
			v = compte_voisins_vivants (i, j, *gc);
			if (est_vivante(i,j,*g)) 
			{ // evolution d'une cellule vivante
				if ( v!=2 && v!= 3 ) {set_morte(i,j,*g);}
				else if (vieillissement == 1){
					if (g->cellules[i][j] >= 8) {set_morte(i,j,*g);}
					else if (v==2 || v==3) {set_tjr_vivante(i,j,*g);}
 				}
			}
			else if (est_non_viable(i, j, *g)); //evolution d'une cellule non viable
			else 
			{ // evolution d'une cellule morte
				
				if ( v==3 ) set_vivante(i,j,*g);
			}
		}
	}
	return;
}

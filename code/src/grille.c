

#include "grille.h"
#include "jeu.h"



void alloue_grille (int l, int c, grille* g){
	g -> nbl = l;
	g -> nbc = c;
	g -> cellules = (int**) malloc (l * sizeof(int*));
	int i,j = 0;
	for (i = 0; i < l; i++) {
		g -> cellules[i] = (int*) malloc (c * sizeof(int));
	}
 	for (i = 0; i < l; i++) {
		for (j = 0; j< c ; j++){
			g -> cellules[i][j]= 0;
		}
	}
}



void libere_grille (grille* g){
	int i = 0;
	 for (i = 0; i < g -> nbl; i++){
		free (g -> cellules[i]);
	}
	free (g -> cellules);
}



void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);
	
	int i,j,n1,n2,l,c,vivantes,nonviables=0;
	
	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);
	
	alloue_grille(l,c,g);
	
	fscanf(pfile, "%d", & vivantes);
	for (n1=0; n1< vivantes; ++n1){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}
	fscanf(pfile, "%d", &nonviables);
	for (n2=0; n2< nonviables; ++n2) {
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_non_viable(i,j, *g);
	}	
	fclose (pfile);
	return;
}

void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;	
}

/*---------------------------------------------------------------------------*/

//compare 2 grilles de la meme taille, renvoie 1 si elles sont les memes et 0 sinon
int memes_grilles_test(grille gs, grille gd){  
	int l=gs.nbl;
	int c=gs.nbc;
	int i, j;
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			if (est_vivante(i, j, gs) != est_vivante(i, j, gd)){
				return 0; 
			}
		}
	}
	return 1;
}

/*-----------------------------------------------------------------------------*/

//teste si la colonie d'une grille est morte, si toutes les cellules sont mortes, 1 si oui, 0 s'il y a tjr de cellules vivantes
int colonie_morte(grille gs){
	int l= gs.nbl;
	int c= gs.nbc;
	int i, j;
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			if (est_vivante(i, j, gs) != 0){
				return 0;
			}
		}
	}
	return 1;
}

/*-----------------------------------------------------------------------------*/
//renvoie la periode cad le nombre de pas de temps pour retrouver sa configuration, 0 si elle n'oscille pas
int oscille(grille gs){
	grille gd, gc;
	alloue_grille(gs.nbl, gs.nbc, &gd);
	alloue_grille(gs.nbl, gs.nbc, &gc);
	copie_grille(gs, gd);
	evolue(&gd, &gc);
	int periode=1;
	int checkfutur = 0;
	while(colonie_morte(gd) != 1 && checkfutur<=200){
		if(memes_grilles_test(gs, gd) == 1){
			return periode;
		}
		else{
			evolue(&gd, &gc);
			periode++;
			checkfutur++;
		}
	}
	return 0;
}
/*---------------------------------------------------------------------------------------------*/
//prend en param une grille qui n'oscille pas dans sa pos. courante et on check si elle oscille pour chacune de ses evolution, si elle devient
//oscillante au bout d'un certain temps, on renvoie ce delai, sinon on renvoie 0
int delai_oscille(grille gs){
	grille gd, gc;
	alloue_grille(gs.nbl, gs.nbc, &gd);
	alloue_grille(gs.nbl, gs.nbc, &gc);
	copie_grille(gs, gd);
	evolue(&gd, &gc);
	int delai=1;
	int checkfutur= 0;
	while(colonie_morte(gd) != 1 && checkfutur<=200){
		if (oscille(gd) != 0) return delai;
		else{
			evolue(&gd, &gc);
			delai++;
			checkfutur++;
		}
	}
	return 0;
}


/*---------------------------------------------------------------------------------------------*/
grille nouv_grille(grille g1){
	char nouv_g[200];
	printf("Entrez le chemin vers une nouvelle grille:\n");
	scanf ("%s", nouv_g);
	init_grille_from_file (nouv_g, &g1);
	return g1;
}
	


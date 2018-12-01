#include "cairo_io.h"





void affiche_ligne_cairo(int c, int* ligne, cairo_t* cr, int x, int y){
	int j; 
	int dim = 35;
	cairo_select_font_face(cr, "sans-serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	for (j=0; j<c; j++){
		if(ligne[j]== -1){
			cairo_set_source_rgb(cr, 1.0, 0.2, 0.2);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			x += 45;
		}
		else if(ligne[j]==1){
			cairo_set_source_rgb(cr, 0.4, 1.0, 0.4);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "1");
			x += 45;
		}
		else if(ligne[j]==2){
			cairo_set_source_rgb(cr, 0.2, 1.0, 0.2);
			cairo_rectangle(cr, x,y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "2");
			x += 45;
		}
		else if(ligne[j]==3){
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "3");
			x += 45;
		}
		else if(ligne[j]==4){
			cairo_set_source_rgb(cr,0.0, 0.8, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "4");
			x += 45;
		}
		else if(ligne[j]==5){
			cairo_set_source_rgb(cr, 0.0, 0.6, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "5");
			x += 45;
		}
		else if(ligne[j]==6){
			cairo_set_source_rgb(cr, 0.0, 0.4, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "6");
			x += 45;
		}
		else if(ligne[j]==7){
			cairo_set_source_rgb(cr, 0.2, 0.4, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 + 6);
			cairo_show_text(cr, "7");
			x += 45;
		}
		else if(ligne[j]==8){
			cairo_set_source_rgb(cr, 0.1, 0.2, 0.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
			cairo_move_to(cr, x+dim/2 - 5, y+dim/2 +6);
			cairo_show_text(cr, "8");
			x += 45;
		}
		else { 
			cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
			cairo_rectangle(cr, x, y, dim, dim);
			cairo_fill(cr);
			x += 45;
		}
	}
	return;
}
	 
/*----------------------------------------------------------------*/
			
void affiche_grille_cairo(grille g, cairo_t* cr){
	int x = 10; 
	int y = 150;
	int i, l = g.nbl, c=g.nbc;
	for(i = 0; i < l ; i++){
		affiche_ligne_cairo(c, g.cellules[i], cr, x, y);
		y += 45;
	}
	y = 150;
	return;
}

/*----------------------------------------------------------------------------*/

void affiche_mode_cairo (int tps, cairo_t* cr){

	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
	
	char str[20];
	sprintf(str, "%d", tps);
	char afftps[40]="Temps: ";
	strcat (afftps, str);
	/*------------------------------------*/
	char str2[20];
	int cvv = compte_voisins_vivants == compte_vv_cyclique;
	sprintf(str2, "%d", cvv);
	char affcyc[40]="Cyclique: ";
	strcat (affcyc, str2);
	/*------------------------------------*/
	char str3[20];
	int vi= vieillissement == 1;  
	sprintf(str3, "%d", vi);
	char affviei[40]= "Vieillissement: ";
	strcat(affviei, str3);
	/*------------------------------------*/
	cairo_move_to(cr, 10, 25);
	cairo_show_text(cr,afftps);
	cairo_move_to(cr, 10, 45);
	cairo_show_text(cr, affcyc);
	cairo_move_to(cr, 10, 65);
	cairo_show_text(cr, affviei);
	
	return;
	
}

/*---------------------------------------------------------------------------------------------*/
void efface_ecran_cairo(cairo_t* cr){
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_paint(cr);
	return;
}
	




			





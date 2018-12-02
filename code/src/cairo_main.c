#include "cairo_io.h"
#include "jeu.h"
#include "grille.h"
#include "io.h"
#define SIZEX 700
#define SIZEY 600


int main (int argc, char *argv[]){
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}
	
	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	compte_voisins_vivants = compte_vv_cyclique;
	vieillissement=0;
	int tps = 0;


	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;
	
	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0, 
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "Jeu de la vie");
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask);
	XMapWindow(dpy, win);
	
	// create cairo surface
	cairo_surface_t *cs; 
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);
	cairo_t* cr;
	cr = cairo_create(cs);

	
	
	
	cairo_set_font_size(cr, 15);
	// run the event loop
	while(1) {
		XNextEvent(dpy, &e);
		if(e.type==Expose && e.xexpose.count<1) { //ouverture de la fenêtre
			if (g.nbl >= 10) XResizeWindow(dpy, win, 900, 700);
			affiche_grille_cairo(g, cr);
			affiche_mode_cairo(tps, cr);
		} 
	/*---------------------------------------------------------------------------*/
		else if(e.type==ButtonPress && e.xbutton.button==Button1){ //clic gauche
			evolue(&g, &gc);
			tps++;
			efface_ecran_cairo(cr);
			affiche_mode_cairo(tps, cr);
			affiche_grille_cairo(g, cr);
			
		}
	/*--------------------------------------------------------------------------*/
		else if(e.type==KeyPress && e.xkey.keycode == 54){ //touche c
			if(compte_voisins_vivants == compte_vv_cyclique){
				compte_voisins_vivants = compte_vv_non_cyclique;
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_grille_cairo(g, cr);
			}
			else if (compte_voisins_vivants == compte_vv_non_cyclique){
				compte_voisins_vivants = compte_vv_cyclique;
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_grille_cairo(g, cr);
			}
		}
	/*--------------------------------------------------------------------------*/
		else if (e.type==KeyPress && e.xkey.keycode == 55){ //touche v
			if (vieillissement == 1){
				vieillissement = 0;
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_grille_cairo(g, cr);
			}
			else if(vieillissement == 0){
				vieillissement = 1;
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_grille_cairo(g, cr);
			}
		}
	/*--------------------------------------------------------------------------*/
		else if (e.type==KeyPress && e.xkey.keycode == 57){ //touche n
			grille g1, g2;
			g1 = nouv_grille(g1);
			alloue_grille(g1.nbl, g1.nbc, &g2); //il faut que les dimensions de la grille temp. soient les memes que celles de la grille principale 
			
			if (g1.nbl >= 10) XResizeWindow(dpy, win, 900, 700);
			if (g1.nbl < 10) XResizeWindow(dpy, win, SIZEX, SIZEY);
			tps=0;
			efface_ecran_cairo(cr);
			affiche_grille_cairo (g1, cr);
			affiche_mode_cairo (tps, cr);
			g = g1;
			gc = g2;
			
			
		}
	/*--------------------------------------------------------------------------*/
		else if(e.type==KeyPress && e.xkey.keycode == 32){ //touche o
			if (oscille(g) == 0){//la grille n'oscille pas
				int d = delai_oscille(g);
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_non_oscille(d, cr);
				affiche_grille_cairo(g, cr);
			}
			else{
				efface_ecran_cairo(cr);
				affiche_mode_cairo(tps, cr);
				affiche_oscille(oscille(g), cr);
				affiche_grille_cairo(g, cr);
			}
		}	 
				
	/*--------------------------------------------------------------------------*/
		else if (e.xbutton.button==Button3){ //clic droit
			break;
		}
	
	}

	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
	return 0;
}  


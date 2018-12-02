/**
  *\file cairo_io.h
  *\brief Fichier contenant les fonctions nécessaires à un affichage graphique cairo
  *\date 1.Decembre.2018
  */



#ifndef CAIRO_IO
#define CAIRO_IO

#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xlib.h>
#include <assert.h>
#include <string.h>
#include "grille.h"
#include "jeu.h"

/**
  *\fn void affiche_ligne_cairo(int c, int* ligne, cairo_t* cr, int x, int y)
  *\brief Fonction qui gere l'affichage d'une ligne de la grille dans une fenetre graphique
  *\param c Entier désignant le nombre de colonnes dans la grille
  *\param ligne Tableau d'entiers contenant l'age des differentes cellules, une ligne de la grille
  *\param cr Pointeur vers le contexte cairo courant
  *\param x Entier, définit la position horizontale du coin superieur gauche de la grille
  *\param y Entier, définit la position verticale du coin superieur gauche de la grille
  *\return void La fonction de renvoie rien, à la sortie de la fonction une ligne de la grille sera affiché dans la fenetre graphique
  */
void affiche_ligne_cairo(int c, int* ligne, cairo_t* cr, int x, int y);  


/**
  *\fn void affiche_grille_cairo(grille g, cairo_t* cr)
  *\brief Fonction qui gere l'affichage d'une grille dans une fenetre graphique
  *\param g Grille à afficher
  *\param cr Pointeur vers le contexte cairo courant
  *\return void La fonction ne renvoie rien, à la sortie de la fonction la grille g sera affiché dans la fenetre graphique
  */
void affiche_grille_cairo(grille g, cairo_t* cr); 


/**
  *\fn void affiche_mode_cairo(int tps, cairo_t* cr)
  *\brief Fonction qui gere l'affichage du temps et l'etat des differents modes(cyclique et vieillissement)
  *\param tps Entier, ayant pour valeur le nombre de pas de temps à afficher
  *\param cr Pointeur vers le contexte cairo courant
  *\return void La fonction de renvoie rien, elle affiche le temps, si le vieillissement est activé et si le
  * mode cyclique est activé
  */ 
void affiche_mode_cairo (int tps, cairo_t* cr); 


/**
  *\fn void efface_ecran_cairo(cairo_t* cr)
  *\brief Fonction qui peint la fenetre en noir pour "effacer" ce qui etait affiché
  *\param cr Pointeur vers le contexte cairo courant
  *\return void La fonction ne renvoie rien, à la sortie de la fonction on aura une fenetre completement noire
  */
void efface_ecran_cairo(cairo_t* cr); //efface les modes 


/**
  *\fn void affiche_oscille(int os, cairo_t* cr)
  *\brief Fonction qui affiche la periode d'oscillation dans la fenetre graphique. 
  * La fonction est utilisée dans le cas ou la colonie est oscillante.
  *\param os Entier, désigne la periode d'oscillation à afficher 
  *\param cr Pointeur vers le contexte cairo courant 
  *\return void La fonction ne renvoie rien, elle affiche simplement la phrase
  * "Colonie oscillante, Periode: " et la periode d'oscillation dans la fenetre
  */
void affiche_oscille(int os, cairo_t* cr);


/**
  *\fn void affiche_non_oscille(int d, cairo_t* cr)
  *\brief Fonction qui affiche la phrase "Colonie non oscillante" dans le cas d'une colonie
  * qui n'oscille pas et n'a pas de delai d'oscillation ou la phrase "La colonie deviendra oscillante, Delai: " et le delai
  * d'oscillation dans le cas d'une colonie qui n'oscille pas, mais oscillera au bout d'un certain temps.
  *\param d Entier, le delai d'oscillation à afficher, vaut 0 si la colonie n'oscillera pas.
  *\param cr Pointeur vers le contexte cairo courant
  *\return void La fonction ne renvoie rien, elle affiche simplement au bout de combien de temps, la colonie oscillera
  * ou si elle n'oscillera pas.
  */
void affiche_non_oscille(int d, cairo_t* cr);



#endif

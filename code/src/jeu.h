/**
  *\file jeu.h
  *\brief Fichier definissant les prototypes des fonctions nécessaires au bon déroulement
  * jeu 
  *\date 9.Novembre.2018
  */


#ifndef __JEU_H
#define __JEU_H

#include "grille.h"


/**
  *\fn static inline int modulo(int i, int m)
  *\brief Fonction qui est utilisée dans le mode cyclique pour traiter
  * correctement les cellules qui se trouvent sur les bords de la grille
  *\param i Entier désignant l'indice, soit colonne, soit ligne de la cellule
  *\param m Entier désignant le nombre de lignes ou des colonnes de la grille
  *\return static inline int Entier qui est le reste de la division de (i+m) par m 
  */
// modulo modifié pour traiter correctement les bords i=0 et j=0
// dans le calcul des voisins avec bords cycliques
static inline int modulo(int i, int m) {return (i+m)%m;}


/**
  *\fn int compte_vv_cyclique (int i, int j, grille g)
  *\brief Fonction qui compte le nombre de voisins vivants de la cellule (i,j)
  * avec bords cycliques
  *\param i Entier indiquant le numero de ligne de la cellule 
  *\param j Entier indiquant le numero de colonne de la cellule 
  *\param g Grille dans laquelle se trouve la cellule en question
  *\return int Entier indiquant le nombre de voisins vivants de la cellule (i,j)
  */  
int compte_vv_cyclique (int i, int j, grille g);


/**
  *\fn void evolue (grille *g, grille *gc)
  *\brief Fonction qui fait évoluer la grille g d'un pas de temps 
  *\param g Pointeur vers une grille qu'on veut faire évoluer 
  *\param gc Pointeur vers une grille qui nous servira de copie temporaire
  * de la grille g qu'on utilisera pour compter le nombre de voisins vivants de chaque cellule 
  *\return void La fonction ne renvoie rien mais à la fin de la fonction, la grille g aurait
  * evolué d'un pas de temps
  */
void evolue (grille *g, grille *gc);

/**
  *\fn int compte_vv_non_cyclique (int i, int j, grille g)
  *\brief Fonction qui compte le nombre de voisins vivants de la cellule (i,j)
  * avec bords non cycliques
  *\param i Entier indiquant le numero de ligne de la cellule
  *\param j Entier indiquant le numero de colonne de la cellule
  *\param g Grille dans laquelle se trouve la cellule en question
  *\return int Entier indiquant le nombre de voisins vivants de la cellule (i,j)
  */
int compte_vv_non_cyclique (int i, int j, grille g);


int (*compte_voisins_vivants) (int, int, grille); /*!< Pointeur vers une fonction qui prend 
en parametres deux entiers et une grille et qui renvoie un entier*/

#endif

/**
  *\file io.h
  *\brief Fonctions traitant l'affichage et l'effacement 
  *c'est à dire le input et output du jeu de la vie 
  *\date 9.Novembre.2018
  */


#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"

/**
  *\fn void affiche_trait (int c)
  *\brief Fonction qui gère l'affichage d'un trait horizontal qui délimite
  * les lignes et les colonnes
  *\param c Entier définissant le nombre de colonnes dans le trait
  *\return void La fonction ne renvoie rien mais à la sortie de la fonction
  * un trait qui delimitera deux lignes et c nombre de colonnes sera affiché
  */
void affiche_trait (int c);


/**
  *\fn void affiche_ligne_sans_age (int c, int* ligne)
  *\brief Fonction qui gère l'affichage d'une ligne de la grille
  *\param c Entier définissant le nombre de colonnes à parcourir
  *\param ligne Tableau d'entiers contenant des informations sur l'état des cellules,
  * si il y a un 0 dans le tableau cela veut dire que la cellule est morte,
  * ou qu'elle est vivante s'il y a un entier different de 0.
  *\return void La fonction ne renvoie rien mais à la sortie de la fonction, une ligne sera affiché
  */
void affiche_ligne_sans_age (int c, int* ligne);


/**
  *\fn void affiche_ligne_age (int c, int* ligne)
  *\brief Fonction qui gèr l'affichage d'une ligne de la grille avec l'age de chaque cellule
  *\param c Entier définissant le nombre de colonnes dans la ligne (nbr de colonnes à parcourir
  *\param ligne Tableau d'entiers à afficher, chaque entier est l'age d'une cellule
  *\return void La fonction ne renvoie rien, elle affiche une ligne de la colonne avec l'age de chaque cellule
  */
void affiche_ligne_age (int c, int* ligne);


/**
  *\fn void affiche_grille (grille g)
  *\brief Fonction que gère l'affichage d'un grille
  *\param g Grille à afficher
  *\return void La fonction ne renvoie rien mais à la sortie de la fonction
  * une grille sera affiché
  */
void affiche_grille (grille g);



/**
  *\fn void efface_grille (grille g)
  *\brief Fonction qui gère l'effacement d'une grille 
  *\param g Grille à effacer 
  *\return void La fonction ne renvoie rien mais à la sortie de la fonction,
  * la grille g sera effacé
  */ 

void efface_grille (grille g);

/**
  *\fn void debut_jeu(grille *g, grille *gc)
  *\brief Fonction qui gère la partie dynamique du jeu, l'affichage de la grille
  * à chaque étape de l'evolution et les differentes options après le commencement
  * du jeu
  *\param g Pointeur vers une grille qu'on utilisera dans le jeu
  *\param gc Pointeur vers une grille qui servira de copie temporaire de la grille pointé par g
  * pour effectuer l'evolution correctement pendant le jeu
  *\return void La fonction ne renvoie rien. En l'appelant on commence le jeu et à la sortie de la fonction
  * le jeu est fini.
  */
void debut_jeu(grille *g, grille *gc);

/**
  *\fn void affiche_temps (int tps)
  *\brief Fonction utilisée pour afficher le temps d'evolution 
  *\param tps Entier désignant la valeur du temps à afficher
  *\return void La fonction ne renvoie rien mais elle affiche dans la fenetre de la console
  * Temps = tps
  */
void affiche_temps (int tps);

/**
  *\fn void efface_temps()
  *\brief Fonction qui déplace le curseur d'une ligne vers le haut, utilisée pour effacer l'affichage du temps
  *\param void
  *\return void La fonction efface l'affichage du temps dans la fenêtre de la console
  */
void efface_temps();

void (*affiche_ligne) (int, int*); /*!< Pointeur vers une fonction qui prend 
en parametres un entier et un pointeur vers un entier et qui renvoie un void*/

#endif

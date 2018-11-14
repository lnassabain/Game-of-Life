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
  *\fn void affiche_ligne (int c, int* ligne)
  *\brief Fonction qui gèr l'affichage d'une ligne de la grille avec l'age de chaque cellule
  *\param c Entier définissant le nombre de colonnes dans la ligne (nbr de colonnes à parcourir)
  *\param ligne Tableau d'entiers à afficher, chaque entier est l'age d'une cellule
  *\return void La fonction ne renvoie rien, elle affiche une ligne de la grille avec l'age de chaque cellule
  */
void affiche_ligne (int c, int* ligne);


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
  *\fn void affiche_mode (int tps)
  *\brief Fonction utilisée pour afficher le temps d'evolution est l'etat des differents modes 
  *\param tps Entier désignant la valeur du temps à afficher
  *\return void La fonction ne renvoie rien, elle affiche le temps, si le vieillissement est activé et si le
  * mode cyclique est activé
  */
void affiche_mode (int tps);

/**
  *\fn void efface_mode()
  *\brief Fonction qui déplace le curseur de 3 lignes vers le haut, utilisée pour effacer l'affichage du temps
  * et l'affichage des etats des differents modes
  *\param void La fonction ne prend rien en parametres
  *\return void La fonction efface l'affichage du temps et des etats des differents modes
  */
void efface_mode();

int vieillissement; /*!< Entier dont la valeur determine si le vieillissement est activé ou desactivé*/

#endif

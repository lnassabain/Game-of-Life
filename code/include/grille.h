/**
  *\file grille.h
  *\brief Structure des grilles, fonctions traitant les grilles et l'etat des cellules
  *\date 9.Novembre.2018
  */


#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
  *\struct grille
  *\brief Structure définissant une grille 
  *\param nbl entier désigant le nombre de lignes.
  *\param nbc entier désignant le nombre de colonnes.
  *\param cellules un tableau de tableau de cellules qui sont represntés par des entiers.
  */ 
// structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
typedef struct {int nbl; int nbc; int** cellules;} grille;


/**
  * \fn void alloue_grille(int l, int c, grille* g)
  * \brief alloue une grille de taille l*c, et initialise toutes les cellules à mortes
  * \param l entier désignant le nombre de lignes. 
  * \param c entier désignant le nombre de colonnes.  
  * \param g l'adressede la grille qu'on alloue et initialise.
  * \return void, la fonction ne renvoie rien mais g est maintenant l'adresse d'une grille alloué et
  * initialisée.
  */ 
// alloue une grille de taille l*c, et initialise toutes les cellules à mortes
void alloue_grille (int l, int c, grille* g);


/**
  * \fn void libere_grille (grille* g)
  * \brief fonction qui libére (free) une grille allouée
  * \param g pointeur(adresse) vers une grille alloué
  * \return void, la fonction ne renvoie rien mais g est maintenant un pointeur vers une grille 
  * vide(ne contient pas de cellules)
  */
// libère une grille
void libere_grille (grille* g);



/**
  * \fn init_grille_from_file (char* filename, grille* g)
  * \brief alloue et initialise la grille g à partir d'un fichier 
  * \param filename tableau(chaine) de caractères désignant le nom du fichier dans 
  * lequel se situe la grille à initialiser et allouer
  * \param g pointeur vers une grille qu'on va allouer et initialiser à partir du fichier rentré en 
  * parametres
  * \return void la fonction ne renvoie rien mais à la sortie de la fonction, g est un pointeur 
  * vers la grille dont la description se situait dans le fichier 
  */
void init_grille_from_file (char * filename, grille* g);


/**
  *\fn static inline void set_vivante(int i, int j, grille g)
  *\brief rend vivante la cellule de coordonnées (i,j) de la grille g
  *\param i entier désignant la ligne dans laquelle se trouve la cellule 
  *\param j entier désignant la colonne dans laquelle se trouve la cellule
  *\param g grille dans laquelle on veut rendre une cellule vivante
  *\return static inline void la fonction ne renvoie rien mais à la sortie de la fonction, la cellule
  * de coordonnées (i, j) de la grille g est vivante
  */ 
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}


/**
  *\fn static inline void set_non_viable (int i, int j, grille g)
  *\brief La fonction rend la cellule de coordonnées (i, j) de la grille g, non viable
  *\param i Entier désignant la ligne dans laquelle se trouve la cellule
  *\param j Entier désignant la colonne dans laquelle se trouve la cellule
  *\param g Grille dans laquelle se trouve la cellule qu'on veut rendre non viable
  *\return static inline void La fonction ne renvoie rien, à la sortie de la fonction, la cellule de coordonnée (i, j) de la grille g aura pour valeur -1 (non viable)
  */
static inline void set_non_viable (int i, int j, grille g){g.cellules[i][j] = -1;}


/**
  *\fn static inline void set_morte(int i, int j, grille g)
  *\brief rend morte la cellule de coordonnées (i, j) de la grille g
  *\param i entier désignant la ligne dans laquelle se trouve la cellule
  *\param j entier désignant la colonne dans laquelle se trouve la cellule
  *\param g grille dans laquelle on veut rendre une cellule morte
  *\return static inline void la fonction ne renvoie rien mais à la sortie de la fonction, la cellule
  * de coordonnées (i, j) de la grille g est morte
  */
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/**
  *\fn static inline void set_tjr_vivante (int  i, int j, grille g)
  *\brief Incremente l'age de la cellule si elle set toujours vivante au temps = temps+1
  *\param i Entier désignant la ligne dans laquelle se trouve la cellule
  *\param j Entier désignant la colonne dans laquelle se trouve la cellule
  *\param g Grille dans laquelle se trouve la cellule dont on veut incrementer l'age
  *\return static inline void La fonction ne renvoie rien, à la sortie de la fonction, l'age de la cellule de position (i,j) est incrementé
  */
static inline void set_tjr_vivante(int i, int j, grille g){g.cellules[i][j] += 1;}

/**
  *\fn static inline int est_vivante(int i, int j, grille g)
  *\brief teste si la cellule (i,j) de la grille g est vivante
  *\param i entier désignant la ligne dans laquelle se trouve la cellule 
  *\param j entier désignant la colonne dans laquelle se trouve la cellule
  *\param g grille dans laquelle on veut tester si une cellule est vivante 
  *\return static inline int la fonction nous renvoie un booléen, 1 ou 0 selon l résultat
  * du test
  */
static inline int est_vivante(int i, int j, grille g){
	if (i<0 || i >= g.nbl) return 0;
	else if (j<0 || j >= g.nbc) return 0;	
	else return (g.cellules[i][j] >= 1);
}


/**
  *\fn static inline int est_non_viable(int i, int j, grille g)
  *\brief Fonction qui teste si une cellule est non viable
  *\param i Entier définissant la ligne dans laquelle se trouve la cellule
  *\param j Entier définissant la colonne dans laquelle se trouve la cellule
  *\param g Grille dans laquelle on veut tester si la cellule de coordonnées (i,j) est non viable
  *\return static inline int La fonction renvoie un entier, vrai ou faux, 1 ou 0 selon le résultat du test
  */
static inline int est_non_viable(int i, int j, grille g){return g.cellules[i][j]==-1;}


/**
  * \fn void copie_grille (grille gs, grille gd)
  * \brief la fonction recopiera la grille gs dans la grille gd 
  * \param gs grille à recopier
  * \param gd grille dans laquelle on recopiera la grille gs 
  * \return void A la sortie de la fonction, la grille gd sera la même que la grille gs
  */
void copie_grille (grille gs, grille gd);


/**
  *\fn int memes_grilles_test(grille gs, grille gd)
  *\brief La fonction compare 2 grilles gs et gd qui sont de la meme taille et renvoie 1 si elles ont la meme configuration et 0 sinon 
  *\param gs Grille, premiere grille à comparer
  *\param gd Grille, deuxieme grille à comparer
  *\return int 1 ou 0 selon le resultat du test.
  */
int memes_grilles_test(grille gs, grille gd);


/**
  *\fn int colonie_morte(grille gs)
  *\brief La fonction teste si toutes les cellules d'une grille sont mortes et renvoie 1 si oui ou 0 s'il y a toujours
  * de cellules vivantes.
  *\param gs Grille sur laquelle on fait le test
  *\return int 1 ou 0 selon le resultat du test.
  */
int colonie_morte(grille gs);


/**
  *\fn int oscille(grille gs)
  *\brief La fonction fait evoluer la grille donnée en parametre tant qu'elle contient des cellules vivantes 
  * et tant qu'elle ne depasse pas 200 evolution et compare chacune des configurations possibles avec la configuration courante
  * de la colonie. La fonction renvoie la periode d'oscillation.
  *\param gs Grille contenant une colonie qu'on veut savoir si elle oscille
  *\return int La periode d'oscillation si elle existe, 0 si la colonie n'oscille pas
  */
int oscille(grille gs);


/**
  *\fn grille nouv_grille(grille g1)
  *\brief La fonction innitialise une nouvelle grille dont le chemin est entré dans le terminal 
  *\param g1 Grille qu'on alloue et initialise à partir d'un fichier entré dans le terminal 
  *\return grille Une grille alloué et initialisée dont les informations se trouvaient dans le fichier
  * entré dans le terminal.
  */
grille nouv_grille(grille g1);


/**
  *\fn int delai_oscille(grille gs)
  *\brief La fonction prend en parametre une grille qui n'oscille pas dans sa configuration courante et on verifie
  * si elle oscille pour chacune de ses evolutions, si elle devient oscillante au bout d'un certain temps,
  * on renvoie ce delai, sinon on renvoie 0.
  *\param gs Grille pour laquelle on veut tester si elle oscillera dans le futur
  *\return int Le delai au bout duquel une colonie devient oscillante, 0 si elle ne le devient pas
  */
int delai_oscille(grille gs);

#endif

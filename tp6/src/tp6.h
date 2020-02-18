#ifndef __TP6_H_
#define __TP6_H_

#define N 5


#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*! void init(int ttint_plateau[N][N])
\param int ttint_plateau[N][N]
\brief initialise à -1 la grille de jeu*/
void init(int ttint_plateau[N][N]);

/*! void affichage(int ttint_plateau[N][N])
\param int ttint_plateau[N][N]
\brief affiche la grille sous forme de print, remplace les valeurs -1 1 et 2*/
void affichage(int ttint_plateau[N][N]);

/*! int jouer(int ttint_tableau[N][N],int int_joueur, int int_x)
\param int ttint_tableau[N][N]
\param int int_joueur
\param int int_x
\brief verifie si une case est vide sinon, pose le chiffre du joueur correspondant*/
int jouer(int ttint_tableau[N][N],int int_joueur, int int_x);

/*! agagne(int ttint_plateau[N][N])
\param int ttint_tableau[N][N]
\brief verifie les combinaisons possibles de victoires*/
int agagne(int ttint_plateau[N][N]);

/*! void tourdejeu (int ttint_plateau[N][N])
\param int ttint_tableau[N][N]
\brief fait jouer les joueurs*/
void tourdejeu (int ttint_plateau[N][N]);

#endif
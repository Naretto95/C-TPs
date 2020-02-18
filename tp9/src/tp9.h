#ifndef __TP9_H_
#define __TP9_H_

#define hauteur 5
#define largeur 5

/*! void creergrille(int grille[hauteur][largeur])
\param int grille[hauteur][largeur]
\brief permet de creer une grille*/
void creergrille(int grille[hauteur][largeur]);

/*! void creergrille(int grille[hauteur][largeur])
\param int grille[hauteur][largeur]
\brief permet d'afficher la grille*/
void affichergrille(int grille[hauteur][largeur]);

/*! int voisinnord(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin nord*/
int voisinnord(int grille[hauteur][largeur],int x, int y);

/*! int voisinnordest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin nord est*/
int voisinnordest(int grille[hauteur][largeur],int x, int y);

/*! int voisinest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin est*/
int voisinest(int grille[hauteur][largeur],int x, int y);

/*! int voisinsudest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin sud est*/
int voisinsudest(int grille[hauteur][largeur],int x, int y);

/*! int voisinsud(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin sud*/
int voisinsud(int grille[hauteur][largeur],int x, int y);

/*! int voisinsud ouest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin sud ouest*/
int voisinsudouest(int grille[hauteur][largeur],int x, int y);

/*! int voisinsudouest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin ouest*/
int voisinouest(int grille[hauteur][largeur],int x, int y);

/*! int voisinnordouest(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de renvoyer le voisin nord ouest*/
int voisinnordouest(int grille[hauteur][largeur],int x, int y);

/*! int comptecellulevoisinage(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de compter le nombre de voisin*/
int comptecellulevoisinage(int grille[hauteur][largeur],int x, int y);

/*! int calculernouvellevaleur(int grille[hauteur][largeur],int x, int y)
\param int grille[hauteur][largeur]
\param int x
\param int y
\brief permet de calculer la nouvelle valeur de la celule*/
int calculernouvellevaleur(int grille[hauteur][largeur],int x, int y);

/*! void calculernouvellegrille(int grille[hauteur][largeur])
\param int grille[hauteur][largeur]
\brief renvoi la grille apres changement de valeur des cellules*/
void calculernouvellegrille(int grille[hauteur][largeur]);

/*! void calculernouvellegrille(int grille[hauteur][largeur])
\param int grille[hauteur][largeur]
\param int n
\brief creer le jeu de la vie*/
void jeudelavie(int grille[hauteur][largeur],int n);



#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>


#endif
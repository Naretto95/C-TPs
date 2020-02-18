#ifndef __TP7_H_
#define __TP7_H_

#define N 6
/*! void tri_insertion(int tableau[N])
\param int tableau[N]
\brief tri de la maniere tri insertion*/
void tri_insertion(int tableau[N]);
/*! copiersoustableau(int* src, int debut, int fin)
\param int* src
\param int debut
\param int fin
\brief copie un tableau selon le debut et la fin*/
int* copiersoustableau(int* src, int debut, int fin);
/*! void fusion(int* tab1, int taille1, int* tab2,int taille2, int* tabRes)
\param int* tab1
\param int taille1
\param int* tab2
\param int taille2
\param int* tabRes
\brief fusionne deux tableaux*/
void fusion(int* tab1, int taille1, int* tab2,int taille2, int* tabRes);
/*! void triFusion(int* tab, int taille)
\param int* tab
\param int taille
\brief tri un tableau de la maniere tri fusion*/
void triFusion(int* tab, int taille);
/*! void minMaxTableau(int* tab, int taille, int* min,int* max)
\param int* tab
\param int taille
\param int* min
\param int* max
\brief donne la valeur max et min d'un tableau*/
void minMaxTableau(int* tab, int taille, int* min,int* max);
/*! void histogramme(int* tab, int taille, int* histo, int tailleH, int min)
\param int* tab
\param int taille
\param int* histo
\param int tailleH
\param int min
\brief donne la drequence d'apparitions des nombres d'un tableau*/
void histogramme(int* tab, int taille, int* histo, int tailleH, int min);
/*! void triDenombrement(int* tab, int taille)
\param int* tab
\param int taille
\brief tri de la maniere tri par denombrement*/
void triDenombrement(int* tab, int taille);



#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>


#endif
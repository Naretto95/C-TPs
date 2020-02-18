#ifndef __TP8_H_
#define __TP8_H_

#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define	Pi  3.14159265359 
/*! void resolution(double a,double b,double c)
\brief resout les equations du second degrée*/
void resolution(double a,double b,double c);
/*! void afficher()
\brief demande a l'utilisateur les valeurs de l'equation*/
void afficher();
/*! void approcher(double a, double b,double c, double d)
\brief resout les equations du troisieme degrée*/
void approcher(double a, double b,double c, double d);
/*! void afficher2()
\brief demande a l'utilisateur les valeurs de l'equation*/
void afficher2();

#endif
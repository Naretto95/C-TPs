#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q1.c
\brief question 1 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir un chiffre, le renvois*/


int main (int argc, char** argv) {
	int int_nb;
	printf ("Veuillez saisir un nombre : ");
	scanf ("%d", &int_nb);

    printf("Vous avez saisie : %d ", int_nb);
    return 0;
}
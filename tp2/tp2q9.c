#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q9.c
\brief question 9 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande un nombre et retourne un nombre d'année correspondant*/

int main(int argc, char** argv) {
    int n;
    int i;/*declaration de variables*/
    int int_min;
    int int_max;

    printf ("taille de la liste: ");/*on demande la taille du tableau*/
	scanf ("%d", &n);

    int liste[n]; /*declaration de la liste*/

    printf("Entrer les elements du tableau\n");
    for(i=0; i<n; i++) { 
        scanf ("%d",&liste[i]);
    }

    int_min = liste[0];
    int_max = liste[0];

    for(i=0; i<n; i++) { /*on compare le min et le max au chiffre de positionement i dans la liste, si il est inferieur a min, il le remplace, si il est superieur a max, il le remplace sinon il zap*/
        if (liste[i] <= int_min){
            int_min = liste[i];
        }
        if (liste[i] >= int_max){
            int_max = liste[i];
        }
    }

    printf("min : %d, max : %d.\n", int_min, int_max);

	return 0;
}
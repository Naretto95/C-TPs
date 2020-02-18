#include <stdio.h>/*Autorise l'emploi de printf et de scanf.*/
#include <stdlib.h> /*Autorise l'emploi de exit.*/

/*! \author Lilian Naretto <narettolil@eisti.eu>
\date 15 octobre 2019
\file tp3q1.c
\brief question 1 du tp3
\version 0.1 premier jet*/

/*! \fn int saisieentier()
\return n, un chiffre
\brief demande de saisir un chiffre, le renvois*/

int saisieentier(){
    int n;
    printf("ecrit un entier : ");
    scanf("%d",&n);
    if (n ==0)
    {
        exit (1);
    }
    
    return n;
}
/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir un chiffre, le renvois*/

int main(int argc, char** argv){
    int nb;
    nb=saisieentier();
    printf("%d\n",nb);
    return 0;
}
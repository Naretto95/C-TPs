#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q8.c
\brief question 8 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande un nombre et retourne un nombre d'année correspondant*/

int main(int argc, char** argv){
    int int_argent;/*declaration de variables*/
    int int_annee;
    float int_interet;
    int_annee=0;
    int_interet=0;
    printf("donne le nombre d'argent : ");
    scanf("%d",&int_argent);
    while (int_interet <=1000) /*tant que l'interet est inferieur à 1000, on continue*/
    {
        int_interet= (int_argent*3.5)/100.;
        int_argent= int_argent + int_interet;
        int_annee++;/*on incrémente les années*/
    }
    printf("le nombre d'année nécessaire pour beneficier d'un pret des de : %d ",int_annee);
    return 0;
}


#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q3.c
\brief question 3 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir deux chiffres, renvoi ces chiffres*/

int main(int argc, char** argv){
    int int_x;/*declarations de variables*/
    int int_y;
    printf("donne un premier chiffre : \n");
    scanf("%d",&int_x);
    printf("donne un second chiffre : \n");
    scanf("%d",&int_y);
    printf("les chiffres sont :%d ",int_x);
    printf("%d\n",int_y);
    return 0;
}
#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 15 octobre 2019
\file tp3q2.c
\brief question 2 du tp3
\version 0.1 premier jet*/

/*! \fn int bidon()
\return n, un chiffre
\brief affiche un chiffre, demande de saisir un chiffre, le renvois*/

int bidon(){
    int n;
    printf("%d\n",n);
    printf("donne un chiffre :");
    scanf("%d",&n);
    printf("%d",n);
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir un chiffre, le renvois*/

int main(int argc, char** argv){
    int n;
    printf("%d\n",n);
    printf("donne un chiffre :");
    scanf("%d",&n);
    printf("%d",n);
    bidon();
    printf("%d\n",n);
    return 0;
}
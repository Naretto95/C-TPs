#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q4.c
\brief question 4 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir des informations, renvoi ces informations*/

int main(int argc, char** argv){
    char str_nom[29];/*declarations de variables*/
    char str_prenom[29];/*29 pour la limite de longueur*/
    int int_jour;
    char str_mois[10];
    int int_annee;
    printf("entrez votre nom : ");
    scanf("%s",str_nom);
    printf("\nentrez votre prenom : ");
    scanf("%s",str_prenom);
    printf("\nentrez votre date de naissance : ");
    scanf("%d",&int_jour);
    scanf(" %s",str_mois);
    scanf(" %d",&int_annee);
    printf("\nce que vous avez entré :\n");
    printf("nom :%s", str_nom);
    printf("\nprenom :%s", str_prenom);
    printf("\ndate de naissance :%d ", int_jour);
    printf(" %s",str_mois);
    printf(" %d\n",int_annee);
    return 0;




}
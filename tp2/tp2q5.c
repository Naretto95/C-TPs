#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q5.c
\brief question 5 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir deux chiffres, affiche leur division*/

int main(int argc, char** argv){
    int int_n;/*declarations de variables*/
    int int_d;
    int int_division;
    printf("veuillez saisir le numérateur et le dénominateur: ");
    scanf("%d",&int_n);
    scanf("%d",&int_d);
    if (int_d != 0) /*si le denominateur est different de 0, alors on fait la division*/
    {
        int_division= int_n/int_d;
        printf("%d / %d = %d",int_n,int_d, int_division);
    }
    else
    {
        printf("division impossible");
    }
    
    
    
}
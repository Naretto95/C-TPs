#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 15 octobre 2019
\file tp3q3.c
\brief question 3 du tp3
\version 0.1 premier jet*/

/*! \fn int echange(int nb1,int nb2)
\param int nb1
\param int nb2
\brief echange la valeur de deux variables*/

int echange(int nb1,int nb2){
    int tmp;
    printf("avant echange\n");
    printf("nb1=%d\n",nb1);
    printf("nb2=%d\n",nb2);
    tmp=nb1;
    nb1=nb2;
    nb2=tmp;
    printf("apres echange\n");
    printf("nb1=%d\n",nb1);
    printf("nb2=%d\n",nb2);
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief échange la valeur de deux variables*/

int main(int argc, char** argv){
    int nb1;
    int nb2;
    nb1=5;
    nb2=7;
    printf("avant appel de la fonction\n");
    printf("nb1=%d\n",nb1);
    printf("nb2=%d\n",nb2);
    printf("appel de la fonction echange\n");
    echange(nb1,nb2);
    printf("apres appel de la fonction\n");
    printf("nb1=%d\n",nb1);
    printf("nb2=%d\n",nb2);
    return 0;
}
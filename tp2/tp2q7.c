#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q7.c
\brief question 7 du tp2
\version 0.1 premier jet*/

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande un chiffre de l'echelle, affiche le résultat correspondant*/

 int main(int argc, char** argv){
     int int_echelle;/*declaration de variable*/
     printf("saisir une valeur d'echelle : ");
     scanf("%d",&int_echelle);
     if (int_echelle > 9 || int_echelle < 1)
     { /*cas interdits*/
         printf("erreur");
     }
    switch (int_echelle) { /*association des chiffres avec leur resultat*/
        case 1 : 	printf ("Micro trembelement de tere, non ressenti.\n");
            break;
        case 2 : 	printf ("Tr�s mineur. Non ressenti mais d�tect�.\n");
            break;
        case 3 : 	printf ("Mineur. Causant rarement des dommages.\n");
            break;
        case 4 : 	printf ("L�ger. Secousses notables d'objets � l'int�rieur des maisons.\n");
            break;
        case 5 : 	printf ("Mod�r�. L�gers dommages aux �difices bien construits.\n");
            break;
        case 6 : 	printf ("Fort. Destructeur dans des zones allant jusqu�� 180 km � la ronde si elles sont peupl�es.\n");
            break;
        case 7 : 	printf (" Majeur. Dommages mod�r�s � s�v�res dans des zones plus vastes.\n");
            break;
        case 8 : 	printf ("Important. Dommages s�rieux dans des zones � des centaines de kilom�tres � la ronde.\n");
            break;
        case 9 : 	printf ("D�vasteur. D�vaste des zones sur des milliers de kilom�tres � la ronde.\n");
            break;

        default :
            break;
        }
     
 }
#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 15 octobre 2019
\file tp3q4.c
\brief question 4 du tp3
\version 0.1 premier jet*/

/*! \fn void tablemultiplication(int n)
\param int n
\brief affiche la table de multiplication de l'entier*/

void tablemultiplication(int n){
    int calcul;
    int i;
    if (n > 10)
    { /*traitement du cas où n est superieur a 10*/
        printf("chiffre trop gros\n"); 
    }
    else
    {/*sinon, afficher la table*/
        for (i = 1; i < 10; i++)
        {
            calcul = i*n;
            printf("%d * %d = %d\n",i,n,calcul);
        }
        
    } 
}
/*! \fn float fonction(float n)
\param float n
\brief calcul la fonction voulu pour un n donné*/
float fonction(float n){
    float calcul;
    calcul= n*n*n + 12*n*n + 1;
    return calcul;
}
/*! \fn double doublesoleequation(void)
\param void
\brief calcul la solution de l'equation en utilisant la methode dichotomique*/
double doublesoleequation(void){
    float m;
    float a;
    float b;
    a=(-15);
    b=(-10);
    while ((b-a) > 0.00001)
    {
        
        m =(a+b)/2;
        if (fonction(a)*fonction(m)<0)
        {
            b=m;
        }
        else
        {
            a=m;
        }
        
    }
    return m;
}
/*! \fn int factorielle(int n)
\param int n
\brief retourne la factorielle d'un chiffre donnée*/
int factorielle(int n){
    int i;
    int calcul;
    calcul=1;
    for (i=1; i <= n; i++)
    {
        calcul=calcul*i;
    }
    return calcul;
    
    
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief sert de menu pour choisir les questions voulues*/

int main(int argc, char** argv){
    int n;
    int question;
    printf("choisis le numero de ta question : ");
    scanf("%d",&question);
    if (question > 3 || question < 0)
    {
        printf("mauvais numero\n");
    }
    else
    {
            switch (question)
            {
            case 1:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    tablemultiplication(n);
                    return 0;
                break;
            case 2:
                    printf("%lf\n",doublesoleequation());
                    return 0;
                break;
            case 3:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("%d\n",factorielle(n));

            
            default:
                break;
            }
            }
    
}
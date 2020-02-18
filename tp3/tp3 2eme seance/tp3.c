#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 21 octobre 2019
\file tp3.c
\brief tp3, 2ème séance
\version 0.1 premier jet*/

/*! \fn void affichagesapin(int n)
\param int n
\brief affiche un arbre selon une longueur donné*/

 void affichagesapin(int n){
     int i;
     int k;
     if (n<=1) /* si n=1, pas d'arbre */
     {
         printf("mauvais chiffre\n");
     }
     else /* sinon, on crée l'arbre */
     {
         for ( i = 0; i < n; i++)
     {
         for ( k = 0; k < 1+2*(n-1); k++)

         {
             if (k >= n-1-i && k <= n-1+i)
             {
                printf("*");
             }
             else
             {
                 printf(" ");
             }
             
         }
         printf("\n");
     }
     for ( i = 0; i < 3; i++)
     {
         for (k = 0; k < 1+2*n; k++)
         {
             if (k >= n-2 && k <=n)
             {
                 printf("@");
             }
             else
             {
                 printf(" ");
             }
             
             
         }
         printf("\n");
     }
     }
     
 }

/*! \fn int factoriel(int n)
\param int n
\brief retourne la factorielle d'un chiffre donnée*/
int factoriel(int n){
    int i;
    int k;
    for (k=1; 1 < n; n--)
    {
        k*=n;
    }
    return k;
}

/*! \fn int maxfact(int k)
\param int k
\brief retourne le chiffre qui a sa factorielle majorée par k*/
int maxfact(int k){
    int i;
    if (k<=1)
    {
        printf("mauvais chiffre\n");
    }
    for ( i = 1; factoriel(i) < k; i++)
    {
    }
    printf("%d !\n est majorée",i-1);
    

}

/*! \fn float puissance(float n, int p)
\param float n
\param float p
\brief donne le chiffre n a la puissance p*/

float puissance(float n, int p){
    float a=1;
    if (p<0)
    {
        for (int i = 0; i < -p; i++)
        {
            a*=n;
        }
        return 1/a;
        
    }
    for (int i = 0; i < p; i++)
    {
        a*=n;
    }
    return a;
    
    
}

/*! \fn void estarmstrong(int n)
\param int n
\brief indique si n est un chiffre armstrong*/

void estarmstrong(int n){
    int a=0;
    int r= n;
    for (; r != 0;)
    {
        a += puissance(r%10,3);
        r /= 10;

    }
    if (n == a)
    {
       printf("c'est un chiffre armstrong\n");
    }
    else
    {
        printf("ce n'est pas un chiffre armstrong\n");
    }
    
    
    
}

/*! void binaire (unsigned int n)
\param int n
\brief donne la representation binaire d'un chiffre donnée*/
void binaire (unsigned int n){
    int int_longueur = sizeof(int)*8;
    char char_test[sizeof(int)*8];
    for (int i = 0; i < sizeof(char_test); i++)
    {
        if (n%2 == 0)
        {
            char_test[sizeof(char_test)-1-i] = '0';
        }
        else
        {
            char_test[sizeof(char_test)-1-i] = '1';
        }
        n/=2;     
        
    }
    printf("la representation binaire est : %s\n",char_test);
    
}

/*! void binaire (unsigned int n)
\param int n
\param int p
\brief calcul du coefficient binomial*/
int coefbin(int n, int p){

    if (n<0 || p<0 | n-p<0)
    {
        printf("mauvais chiffres\n");
    }
    else
    {
        return factoriel(n)/(factoriel(n-p)*factoriel(p));
    }
    
    /*complexité : 2^n*/
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief sert de menu pour choisir les questions voulues*/
int main(int argc, char** argv){
    int n;
    int p;
    int question;
    printf("choisis le numero de ta question : ");
    scanf("%d",&question);
    if (question > 5 || question < 0)
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
                affichagesapin(n);
                break;
            case 2:
                printf("donne un chiffre : ");
                scanf("%d",&n);
                maxfact(n);
                break;
            case 3:
                printf("donne un chiffre : ");
                scanf("%d",&n);
                estarmstrong(n);
                break;
            case 4:
                printf("donne un chiffre : ");
                scanf("%d",&n);
                binaire(n);
                break;
             case 5:
                printf("donne deux chiffres n et p : ");
                scanf("%d",&n);
                scanf("%d",&p);
                printf("le coef binomial est : %d\n",coefbin(n,p));
                break;
            default:
                break;
            }
            }
    
}
#include "tp4.h"

/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 25 octobre 2019
\file tp4.c
\brief tp4
\version 0.1 premier jet*/

float approximation(int n){ 
    float i,c,x,y,z;
    c=0;
    float rayon=1.0;
    srand(time(NULL));
    for ( i = 1; i < n; i++)
    {
        x=((float)rand()/(float)(RAND_MAX/rayon));
        y=((float)rand()/(float)(RAND_MAX/rayon));
        z=pow(x,2)+pow(y,2);
        if (z<1)
        {
            c=c+1;
        }
        
    }
    return (4*c)/n;
}

float Madhava(int n){
    float somme=1.0;
    float x=1.0;
    for (int i = 1; i < n; i++)
    {
        x/=-3.0;
        somme+=x/(2*i+1);
    }
    return sqrt(12.0)*somme;
}

float wallis(int n){
  float accum;
  float accum2=2.0;
  float res=1;
  for (accum=1.0 ; accum<=n ; accum=accum+2.0)
  {
    res=res*(accum2/accum);
    if (accum==(accum2+1))
    {
      accum2=accum2+2.0;
      accum=accum-2.0;
    }
  }
  res=res*2;
  return res;
}

float newton(int n){
    float accum = 1;
    float racine =1;
    for ( accum = 1; accum < n; accum++)
    {
        racine = ((2/racine)+racine)/2;
    }
    return racine;
}

float halley(int n){
    float accum = 1;
    float racine =1;
    for ( accum = 1; accum < n; accum++)
    {
        racine = racine*((pow(racine,2)+6)/((3*pow(racine,2)+2)));
    }
    return racine;
}

float theon(int n){
    float accum = 1;
    float racine =1;
    float racine2= 2;
    for ( accum = 1; accum < n; accum++)
    {
        racine = (racine +2)/(racine +1);
    }
    return racine;
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
    if (question > 6 || question < 0)
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
                    printf("pi = %f\n",approximation(n));
                    return 0;
                break;
            case 2:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("pi = %f\n",Madhava(n));
                    return 0;
                break;
            case 3:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("pi = %f\n",wallis(n));
                    return 0;
                break;
            case 4:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("sqrt(2) = %f\n",newton(n));
                    return 0;
                break;
            case 5:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("sqrt(2) = %f\n",halley(n));
                    return 0;
                break;
            case 6:
                    printf("donne un chiffre : ");
                    scanf("%d",&n);
                    printf("sqrt(2) = %f\n",theon(n));
                    return 0;
                break;
            default:
                break;
            }
            }
    
}
#include "tp7.h"
/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 15 novembre 2019
\file tp7.c
\brief tp7
\version 0.1 premier jet*/

 void tri_insertion(int tableau[N]){
    int i, j;
    int valeur;
    for (i = 1; i < N; i++) {
        valeur = tableau[i];
        for (j = i; j > 0 && tableau[j - 1] > valeur; j--) {
            tableau[j]=tableau[j-1];
        }
        tableau[j] = valeur;
    }
}

int* copiersoustableau(int* src, int debut, int fin){
    int taille=fin-debut+1;
    int* dest=malloc(taille*sizeof(int));
    for (int i = 0; i <= fin - debut + 1; ++i)
	{
		dest[i] = src[debut+i];
	}
    return dest;

}

void fusion(int* tab1, int taille1, int* tab2,int taille2, int* tabRes){
    int taille=taille1+taille2;
    int k=0;
    int debut1=0;
    int debut2=0;
    for (int i = 0; i < taille; i++)
    {
        if (debut2>=taille2)
        {
            tabRes[k++]=tab1[debut1++];
        }
        else if (debut1>=taille1)
        {
            tabRes[k++]=tab2[debut2++];
        } else{
            if (tab1[debut1]<=tab2[debut2])
        {
            tabRes[k++]=tab1[debut1++];
        }
        else
        {
            tabRes[k++]=tab2[debut2++];
        }   
        }         
    }        
        
}

void triFusion(int* tab, int taille){
	int taille2 = taille / 2;
	int taille3 = taille - taille2;
	if (taille >= 2)
	{
		int *tab1=copiersoustableau(tab, 0, taille3-1);
		int *tab2=copiersoustableau(tab, taille3, taille-1);
		triFusion(tab1, taille3);
		triFusion(tab2, taille2);
		fusion(tab1, taille3, tab2, taille2, tab);

	}  
}

void minMaxTableau(int* tab, int taille, int* min,int* max){
    *min = tab[0];
	*max = tab[0];
	for (int i = 1; i < taille; ++i)
	{
		if (tab[i] > *max)
		{
			*max = tab[i];
		}else if (tab[i] < *min)
		{
			*min = tab[i];
		}
	}
}

void histogramme(int* tab, int taille, int* histo, int tailleH, int min){
    for (int i = 0; i < taille; ++i)
	{
        histo[tab[i]-min]++;
	}
}

void triDenombrement(int* tab, int taille){
	int* min=malloc(1*sizeof(int));
    int* max=malloc(1*sizeof(int));
	minMaxTableau(tab, taille, min, max);
	int tailleH = *max - *min +1;
	int histo[tailleH] ;
	for (int i = 0; i < tailleH; ++i)
	{
		histo[i] = 0;
	}
	histogramme(tab, taille, histo, tailleH, *min);
	int l = 0;
	for (int i = 0; i < tailleH; ++i)
	{
		for (int v = 0; v < histo[i]; ++v)
		{
			tab[l] = i+*min;
			l++;
		}
	}
}
/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief sert de menu pour choisir les tries voulus*/
int main(int argc, char** argv){
    int i,question;
    int k[N],b[N];
    printf("k[N] = [");
    for ( i = 0; i < N; i++)
    {
        k[i]=rand()%20;
        printf("%d,",k[i]);
    }
    printf("]\n");
    printf("b[N] = [");
    for ( i = 0; i < N; i++)
    {
        b[i]=rand()%20;
        printf("%d,",b[i]);
    }
    printf("]\n");
    printf("tri insertion = 1\n");
    printf("tri fusion = 2\n");
    printf("tri dénombrement = 3\n");
    printf("choisis le type de tri : ");
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
                    tri_insertion(k);
                    printf("k[N] = [");
                    for ( i = 0; i < N; i++)
                    {
                        printf("%d,",k[i]);
                    }
                    printf("]\n");
                    return 0;
                break;
            case 2:
                    triFusion(b,N);
                    printf("b[N] = [");
                     for ( i = 0; i < N; i++)
                    {
                       printf("%d,",b[i]);
                    }
                       printf("]\n");
                    return 0;
                break;
            case 3:
                    triDenombrement(b,N);
                    printf("b[N] = [");
                     for ( i = 0; i < N; i++)
                    {
                       printf("%d,",b[i]);
                    }
                       printf("]\n");
                    return 0;
                break;
            default:
                break;
            }
        }

}
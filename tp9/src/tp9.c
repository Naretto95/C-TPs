#include "tp9.h"
/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 19 novembre 2019
\file tp9.c
\brief tp9
\version 0.1 premier jet*/

void creergrille(int grille[hauteur][largeur]){
    int x;
    for (int i = 0; i < hauteur; i++)
    {
        for (int v = 0; v < largeur; v++)
        {
            printf("valeur case %d - %d : ",i,v);
            scanf("%d",&x);
            while (x!=0 && x!=1)
            {
                printf("mauvais numero, recommence (1 ou 0)\n");
                printf("valeur case %d - %d : ",i,v);
                scanf("%d",&x);
            }
            
            grille[i][v]=x;
        }
        
    }
    
}

void affichergrille(int grille[hauteur][largeur]){
    for (int i = 0; i < hauteur; i++)
    {
        for (int v = 0; v < largeur; v++)
        {
            if (grille[i][v]==1)
            {
                printf("V ");
            }
            else
            {
                printf(". ");
            }
            
        }
        printf("\n");
        
    }
}

int voisinnord(int grille[hauteur][largeur],int x, int y){
    if (x==0)
    {
        return grille[hauteur-1][y];
    } else
    {
        return grille[x-1][y];
    }
    
}

int voisinnordest(int grille[hauteur][largeur],int x, int y){
    if (x==0)
    {
        if (y==largeur-1)
        {
            return grille[hauteur-1][0];
        }
        else
        {
            return grille[hauteur-1][y+1];
        }
        
    } else
    {
        if (y==largeur-1)
        {
            return grille[x-1][0];
        }
        
        return grille[x-1][y+1];
    }
    
}

int voisinest(int grille[hauteur][largeur],int x, int y){
    if (y==largeur-1)
    {
        return grille[x][0];
    } else
    {
        return grille[x][y+1];
    }
    
}

int voisinsudest(int grille[hauteur][largeur],int x, int y){
    if (x==hauteur-1)
    {
        if (y==largeur-1)
        {
            return grille[0][0];
        }
        else
        {
            return grille[0][y+1];
        }
        
    } else
    {
        if (y==largeur-1)
        {
            return grille[x+1][0];
        }
        
        return grille[x+1][y+1];
    }
    
}

int voisinsud(int grille[hauteur][largeur],int x, int y){
    if (x==hauteur-1)
    {
        return grille[0][y];
    } else
    {
        return grille[x+1][y];
    }
    
}

int voisinsudouest(int grille[hauteur][largeur],int x, int y){
    if (x==hauteur-1)
    {
        if (y==0)
        {
            return grille[0][largeur-1];
        }
        else
        {
            return grille[0][y-1];
        }
        
    } else
    {
        if (y==0)
        {
            return grille[x+1][largeur-1];
        }
        
        return grille[x+1][y-1];
    }
    
}

int voisinouest(int grille[hauteur][largeur],int x, int y){
    if (y==0)
    {
        return grille[x][largeur-1];
    } else
    {
        return grille[x][y-1];
    }
    
}

int voisinnordouest(int grille[hauteur][largeur],int x, int y){
    if (x==0)
    {
        if (y==0)
        {
            return grille[hauteur-1][largeur-1];
        }
        else
        {
            return grille[hauteur-1][y-1];
        }
        
    } else
    {
        if (y==0)
        {
            return grille[x-1][largeur-1];
        }
        
        return grille[x-1][y-1];
    }
    
}

int comptecellulevoisinage(int grille[hauteur][largeur],int x, int y){
    int k=0;
    if (voisinnord(grille,x,y)==1)
    {
        k++;
    }
    if (voisinnordest(grille,x,y)==1)
    {
        k++;
    }
    if (voisinnordouest(grille,x,y)==1)
    {
        k++;
    }
    if (voisinsud(grille,x,y)==1)
    {
        k++;
    }
    if (voisinsudest(grille,x,y)==1)
    {
        k++;
    }
    if (voisinsudouest(grille,x,y)==1)
    {
        k++;
    }
    if (voisinest(grille,x,y)==1)
    {
        k++;
    }
    if (voisinouest(grille,x,y)==1)
    {
        k++;
    
    }
    return k;
    
}

int calculernouvellevaleur(int grille[hauteur][largeur],int x, int y){
    if (grille[x][y]==1 && (comptecellulevoisinage(grille,x,y)==2 ||comptecellulevoisinage(grille,x,y)==3))
    {
        return 1;
    }
    else
    {
        if (comptecellulevoisinage(grille,x,y)==3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
        
    }
    
}

void calculernouvellegrille(int grille[hauteur][largeur]){
    int grille2[hauteur][largeur];
    for (int i = 0; i < hauteur; i++)
    {
        for (int v = 0; v < largeur; v++)
        {
            grille2[i][v]=calculernouvellevaleur(grille,i,v);
        }
        
    }
    for (int i = 0; i < hauteur; i++)
    {
        for (int v = 0; v < largeur; v++)
        {
            grille[i][v]=grille2[i][v];
        }
        
    }
    
}

void jeudelavie(int grille[hauteur][largeur],int n){
    for (int i = 0; i < n; i++)
    {
        calculernouvellegrille(grille);
        affichergrille(grille);
        printf("\n");
    }
    
}


/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief lance le jeu*/
int main(int argc, char** argv){
    int l;
    int grille[hauteur][largeur];
    creergrille(grille);
    printf("\n");
    affichergrille(grille);
    printf("nombre d'étapes du jeu de la vie : ");
    scanf("%d",&l);
    printf("\n");
    jeudelavie(grille,l);
}
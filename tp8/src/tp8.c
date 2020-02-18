#include "tp8.h"
/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 30 novembre 2019
\file tp8.c
\brief tp8
\version 0.1 premier jet*/

void error(){
    printf("Mauvais agrument\n");
    printf("liste des arguments :\n");
    printf("Cesar\n");
    printf("Vigenere\n");
    printf("Scytale\n");
}

void error2(){
    printf("mot incorrecte\n");
}

void cesar(){
    int dec;
    char* mot=NULL;
    char* mot2;
    int taille;
    size_t taille2;
    printf("donne un mot : ");
    taille=getline(&mot,&taille2,stdin);
    printf("donne le decalage : ");
    scanf("%d",&dec);
    mot2=malloc((taille+1)*sizeof(char));
    for (int i = 0; i < taille; i++)
    {
        if (mot[i]>=65 && mot[i]<=90)
        {
            mot2[i]=mot[i]-65;
            mot2[i]=mot2[i]+dec;
            mot2[i]=mot2[i]%26;
            mot2[i]=mot2[i]+65;
        }
        else if (mot[i]>=97 && mot[i]<=122)
        {
            mot2[i]=mot[i]-97;
            mot2[i]=mot2[i]+dec;
            mot2[i]=mot2[i]%26;
            mot2[i]=mot2[i]+97;
        }
        else
        {
            mot2[i]=mot[i];
        }
        
          
    }
    mot2[taille]='\0';
    printf("mot codé : %s",mot2);
    printf("\n");   
    
}

void vigenere(){
    char* mot=NULL;
    char* mot2;
    char* mot3=NULL;
    char* mot4;
    int taille,taille3;
    size_t taille2;
    size_t taille4;
    printf("donne un mot : ");
    taille=getline(&mot,&taille2,stdin);
    printf("donne la clé : ");
    taille3=getline(&mot3,&taille4,stdin);
    mot2=malloc((taille+1)*sizeof(char));
    mot4=malloc((taille+1)*sizeof(char));
    for (int k=0,i=0;k<taille-1; k++,i++)
    {
        mot4[k]=mot3[(i)%(taille3-1)];
    }
    mot4[taille-1]='\0';
    for (int i = 0; i < taille; i++)
    {
        if (mot[i]>=65 && mot[i]<=90)
        {
            mot2[i]=mot[i]-65;
            mot2[i]=mot2[i]+(tolower(mot4[i])-97);
            mot2[i]=mot2[i]%26;
            mot2[i]=mot2[i]+65;
        }
        else if (mot[i]>=97 && mot[i]<=122)
        {
            mot2[i]=mot[i]-97;
            mot2[i]=mot2[i]+(tolower(mot4[i])-97);
            mot2[i]=mot2[i]%26;
            mot2[i]=mot2[i]+97;
        }
        else
        {
            mot2[i]=mot[i];
        }
    }
    mot2[taille]='\0';
    printf("mot codé : %s",mot2);
    printf("\n");
    

}

void scytale(){
    char* mot=NULL;
    size_t taille;
    char** tab;
    int taille2,taille3;
    int accum=0;
    printf("donne un mot : ");
    taille2=getline(&mot,&taille,stdin);
    taille3=1;
    while (pow(taille3,2)<taille2-1){
        taille3++;
    }
    tab=malloc((taille3)*sizeof(char*));
    for (int i=0;i<taille3;i++){
        tab[i]=malloc(taille3*sizeof(char));
    }
    for (int i=0;i<taille3;i++){
        for(int v=0;v<taille3;v++){
            tab[i][v]=mot[accum];
            accum++;
        }
   }
   printf("mot codé : ");
   for (int i=0;i<taille3;i++){
        for(int v=0;v<taille3;v++){
            printf("%c",tab[v][i]);
        }
   }
   printf("\n");
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief lance le jeu*/
int main(int argc, char** argv){
    if (argc==1 || argc>2)
    {
        error();
    }
    else
    {
        if (strcmp(argv[1],"Vigenere")==0 || strcmp(argv[1],"vigenere")==0)
        {
            vigenere();
        }
        else if (strcmp(argv[1],"Cesar")==0 || strcmp(argv[1],"cesar")==0)
        {
            cesar();
        }
        else if (strcmp(argv[1],"Scytale")==0 || strcmp(argv[1],"scytale")==0)
        {
            scytale();
        }
        else
        {
            error();
        }
        
        
    }
    
    
}

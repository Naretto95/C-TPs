#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/

/*!
\author Lilian Naretto <narettolil@eisti.eu>
\date 10 octobre 2019
\file tp2q6.c
\brief question 6 du tp2
\version 0.1 premier jet*/

/*!
\fn int bissextile ( int annee)
\param annee, une année du calendrier
\return 1 si bissextile, 0 sinon
\brief dit si une année est bissextile, répond à l'aide d'un booléen*/


int bissextile ( int annee) {
    int int_boolean;
        if((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
            int_boolean=1;
        else
        {
            int_boolean=0;
        }
    return int_boolean;
}

/*!
\fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
\brief demande de saisir une date, renvoi la date du jour suivant*/

int main(int argc, char** argv) {
    
    int int_annee;/*declaration de variables*/
    int int_mois;
    int int_jour;
    printf("Saisir une date : ");
    scanf("%d",&int_jour);
    scanf("%d",&int_mois);
    scanf("%d",&int_annee);
    if (int_jour > 31 || int_mois > 12 ){ /*test les dates interdites*/
        printf("votre date est incorrecte");
    }
    else
    {   
        if (int_mois==1 || int_mois==3 || int_mois==5 || int_mois==7 || int_mois==8 || int_mois==10 || int_mois == 12){ /*traitement de cas où les mois sont en 31 jours*/
            if (int_jour == 31) { /*passage au mois suivant si 31eme jour*/
                int_jour=1;
                if (int_mois==12){ /*si 12eme mois, passage a l'annee suivante*/
                    int_mois=1;
                    int_annee++;
                    printf("%d %d %d",int_jour,int_mois,int_annee);
                }
                else
                { /*sinon, passage au mois suivant*/
                    int_mois++;
                    printf("%d %d %d",int_jour,int_mois,int_annee);
                }
                
            }
            else /*sinon ajouter un jour*/
            {
                int_jour++;
                printf("%d %d %d",int_jour,int_mois,int_annee);
            }
            
        }
        else
        { /*traitement de cas où les mois sont en 30 jours*/
            if (int_jour == 31){
                printf("votre date est incorrecte");
            }
            else { if (int_mois==2){ /*traitement de cas du mois de fevrier*/
                if (bissextile(int_annee)==1){ /*si année bissextile*/
                    if (int_jour==29)
                    {/*si 29eme jour, passage au mois suivant*/
                        int_jour=1;
                        int_mois++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                        
                    }
                    else {/*sinon, on ajoute un jour*/
                        int_jour++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                    }
                    
                }
                else
                {
                    if (int_jour==29)
                    {
                        printf("votre date est incorrecte"); /*cas du jour 29 en année bisextile*/
                    }
                    else
                    { /*sinon, cas habituel*/
                    if (int_jour==28)
                    { /*si 28eme jour, passage au mois suivant*/
                        int_jour=1;
                        int_mois++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                    }
                    else
                    {/*sinon, ajouter un jour*/
                        int_jour++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                    }
                    
                        
                    }
                        
                }
                
            }
            else
            { /*traitement de cas des mois réguliers en 30 jours*/
                    if (int_jour==30)
                    { /*si 30eme jour, passage au mois suivant*/
                        int_jour=1;
                        int_mois++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                    }
                    else
                    { /*sinon, ajouter un jour*/
                        int_jour++;
                        printf("%d %d %d",int_jour,int_mois,int_annee);
                    }
                    
                
            }
            

            }
        }
    }
    return 0;
    
    
}

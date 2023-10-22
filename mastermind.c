#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int compte;
int tentative=1;
int borne_sup;
int borne_inf;

int trackeur1[3]={0};
int trackeur2[3]={0};

void generateur_sequence(int nombres_genere[], int borne_sup, int borne_inf, int compte);

void master_mind(int nombres_genere[],int tentative, int compte);

int main()
{
    printf("\t---***$$$$$$$$$$$***----\n");
    printf("\t---***MASTER MIND***----\n");
    printf("\t---***$$$$$$$$$$$***----\n");
    
    printf("Combien des nombres voulez vous deviner: ");
    scanf("%d", &compte);
    int nombres_genere[compte];
    printf("Entrez le nombre des tentatives: ");
    scanf("%d", &tentative);

    printf("Entrez la borne inf: ");
    scanf("%d", &borne_inf);
    printf("Entrez la borne sup: ");
    scanf("%d", &borne_sup);
    generate_sequence(nombres_genere, borne_sup, borne_inf, compte);
    master_mind(nombres_genere,tentative,compte);
    return 0;
}

void generateur_sequence(int nombres_genere[], int borne_sup, int borne_inf, int compte)
{
    for(int i=0; i<compte; i++)
    {
        nombres_genere[i] = (rand() % (borne_sup - borne_inf + 1)) + borne_inf;
    }
}


void master_mind(int nombres_genere[],int tentative, int compte)
{
    float gagner=compte;
    int iteration=0;
    int sequence_joueur[compte];
    do
    {
        printf("\t***Entrez %d nombres***\t(vie: %d)\n", compte,tentative-iteration);
        for (int i=0; i<compte; i++)
        {
            scanf("%d", &player_sequence[i]);
        }

        printf("original sequence: ");
        for(int i=0; i<compte; i++)
        {
            printf(" %d;", nombres_genere[i]);
        }

        printf("\n");
        for(int i=0; i<compte; i++)
        {
            for(int j=0; j<compte; j++)
            {
                if((nombres_genere[i]==player_sequence[j]) && !trackeur1[i] && !trackeur2[j])
                {
                    if(i==j)
                    {
                        gagner--;
                        printf("indice : (%d==%d): array1=%d array2=%d. bonne position et bonne valeur\n", i,j, nombres_genere[i], sequence_joueur[j]);
                    }else
                    {
                        gagner++;
                        printf("indice : (%d!=%d): array1=%d array2=%d mauvaise position mais bonne valeur\n", i,j, nombres_genere[i], sequence_joueur[j]);
                    }
                    trackeur1[i]=1;
                    trackeur2[j]=1;
            }   }   
        }
        iteration++;
        printf("score=%f\n", gagner);
        if(gagner==0)
        {
            printf("Bravo vous avez gagner\n");
            break;
        }
    }while (iteration<=tentative);

    int nul=0;
    for(int i=0; i<compte; i++)
    {
        if((nombres_genere[i]!=sequence_joueur[i]) && (gagner!=0))
        {
            nul++;
        }
    }
    if(nul>0)
    {
        printf(" Vous avez perdu !\n");
    }
}

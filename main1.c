#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int compte;
int tentative=1;
int borne_sup;
int borne_inf;

int tracker1[3]={0};
int tracker2[3]={0};

void generate_sequence(int generated_number[], int borne_sup, int borne_inf, int compte);

void master_mind(int generated_number[],int tentative, int compte);


int main()
{
    printf("\t---***$$$$$$$$$$$***----\n");
    printf("\t---***MASTER MIND***----\n");
    printf("\t---***$$$$$$$$$$$***----\n");
    
    printf("Combien des nombres voulez vous deviner: ");
    scanf("%d", &compte);
    int generated_numbers[compte];
    printf("Entrez le nombre des tentatives: ");
    scanf("%d", &tentative);

    printf("Entrez la borne inf: ");
    scanf("%d", &borne_inf);
    printf("Entrez la borne sup: ");
    scanf("%d", &borne_sup);
    generate_sequence(generated_numbers, borne_sup, borne_inf, compte);
    master_mind(generated_numbers,tentative,compte);
    return 0;
}

void generate_sequence(int generated_sequence[], int borne_sup, int borne_inf, int compte)
{
    for(int i=0; i<compte; i++)
    {
        generated_sequence[i] = (rand() % (borne_sup - borne_inf + 1)) + borne_inf;
    }
    for(int i=0; i<compte; i++)
    {
        printf("%d;\n",generated_sequence[i]);
    }
}


void master_mind(int generated_number[],int tentative, int compte)
{
    float gagner=compte;
    int iteration=0;
    int player_sequence[compte];
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
            printf(" %d;", generated_number[i]);
        }

        printf("\n");
        for(int i=0; i<compte; i++)
        {
            for(int j=0; j<compte; j++)
            {
                if((generated_number[i]==player_sequence[j]) && !tracker1[i] && !tracker2[j])
                {
                    if(i==j)
                    {
                        gagner--;
                        printf("indice : (%d==%d): array1=%d array2=%d. bonne position et bonne valeur\n", i,j, generated_number[i], player_sequence[j]);
                    }else
                    {
                        gagner++;
                        printf("indice : (%d!=%d): array1=%d array2=%d mauvaise position mais bonne valeur\n", i,j, generated_number[i], player_sequence[j]);
                    }
                    tracker1[i]=1;
                    tracker2[j]=1;
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
        if((generated_number[i]!=player_sequence[i]) && (gagner!=0))
        {
            nul++;
        }
    }
    if(nul>0)
    {
        printf(" Vous avez perdu !\n");
    }
}


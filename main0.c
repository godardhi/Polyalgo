#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int masterMind(char jouer1[][20], char jouer2[][20], int Nmb_couleurs);
void code_couleur(char jouer2[][20], int Nmb_couleurs);
//void afficher(int bool);


int main()
{
	// Début du jeux
	printf("\t------------------------------------------\n");
	printf("\t---------Bienvenu sur Master Mind---------\n");
	printf("\t------------------------------------------\n");

	printf("\t\t**Consignes du jeux**:\n");
	printf("\n\n");
	printf("1.les entres doivent être en miniscule\n");

	printf("2.Les couleurs possible (rouge, bleu, vert, jaune, violet, orange, rose, marron, gris, noir, blanc)\n");

	char oui_non;
	printf("\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("Taper o pour commencer le jeux ou q pour quitter:\n");
	while(oui_non!='o' && oui_non!='q')
	{
		printf("~");
		scanf(" %c", &oui_non);
	}

	if(oui_non=='o')
	{
		// déclaration des variables

		int Nmb_couleurs;

		// Le jouer 2 doit choisir combien le Nmb_couleurs

		printf("Combien des couleurs voulez vous dévine: ");
		scanf(" %d",&Nmb_couleurs);
		printf("\n\n");
		// declaration de tableau de longeur=Nmb_couleurs
	
		char jouer1[Nmb_couleurs][20];
		char jouer2[Nmb_couleurs][20];

		// ordi choisi les couleurs

		code_couleur(jouer2,Nmb_couleurs);

		// Le jeux commence ici

		printf("--C'est a vous de jouer--\n");

		int resultat = masterMind(jouer1,jouer2,Nmb_couleurs);

		if(resultat==1)
		{
			printf("Bravo, vous avez gagner\n");
		}else if(resultat==0)
		{
			printf("Vous n'avez plus d'essais\n");
		}
	}

	return 0;
}

void code_couleur(char jouer2[][20], int Nmb_couleurs)
{
	// pour avoir des nombres quasi aleatoire
	srand(time(NULL));
	// L'intervalle des nombres génère est 0 à 11 les bornes incluses
	
	for(int i=0; i<Nmb_couleurs; i++)
	{
		int nombre = rand() % 11;

		switch(nombre)
		{
			case 0 :
				strcpy(jouer2[i],"rouge");
				break;
			case 1 :
				strcpy(jouer2[i],"bleu");
				break;
			case 2 :
				strcpy(jouer2[i],"vert");
				break;
			case 3 :
				strcpy(jouer2[i],"jaune");
				break;
			case 4 :
				strcpy(jouer2[i],"violet");
				break;
			case 5 :
				strcpy(jouer2[i],"orange");
				break;
			case 6 :
				strcpy(jouer2[i],"rose");
				break;
			case 7 :
				strcpy(jouer2[i],"marron");
				break;
			case 8 :
				strcpy(jouer2[i],"gris");
				break;
			case 9 :
				strcpy(jouer2[i],"noir");
				break;
			case 10 :
				strcpy(jouer2[i],"blanc");
				break;
			default:
				printf("Message: probleme aux niveaux de la fonction code_couleur\n");
				break;
		}

		// la suite des couleurs choisi par l'ordi
		printf("%s,", jouer2[i]);
	}
}

int masterMind(char jouer1[][20], char jouer2[][20], int Nmb_couleurs)
{
	
	int essais=3;
	int iteration=0;
	int bonne_position=0;
	int bonne_couleur=0;
	while(iteration<=essais)
	{
		// le joueur entre une combinaison
		
		printf("Il vous reste %d essais\n\n", essais-iteration);
		for(int i=0; i<Nmb_couleurs; i++)
		{
			printf("Entrez la couleurs %d de votre choix: ", i);
			do
			{	
				scanf("%19s", jouer1[i]);

				// efface '\n'
				while(getchar() != '\n');

			}while(strcmp(jouer1[i],"rouge")!=0 && strcmp(jouer1[i],"bleu")!=0 && strcmp(jouer1[i],"vert")!=0 && strcmp(jouer1[i],"jaune")!=0 
			&&strcmp(jouer1[i],"violet")!=0 && strcmp(jouer1[i],"orange")!=0 && strcmp(jouer1[i],"rose")!=0 &&
			strcmp(jouer1[i],"marron")!=0 && strcmp(jouer1[i],"gris")!=0 && strcmp(jouer1[i],"noir")!=0 && strcmp(jouer1[i],"blanc")!=0);
		} 

		int repetiteur[20] = {0}; // pour éviter les surcomptages des couleurs 

        for (int i = 0; i < Nmb_couleurs; i++)
        {
            for (int j = 0; j < Nmb_couleurs; j++)
            {
                if (strcmp(jouer1[i], jouer2[j]) == 0 && !repetiteur[j])
                {
                    if (i == j)
                    {
                        bonne_position++;
                        printf("###%s correctement placé###\n", jouer1[i]);
                    }
                    else
                    {
                        bonne_couleur++;
                        printf("###%s n'est correctement placé\n###", jouer1[i]);
                    }

                    repetiteur[j]= 1; 
                    break;               
                }
            }
        }	
		if(bonne_position==Nmb_couleurs)
		{
			return 1;
		}
		iteration++;
	}
	return 0;
}	

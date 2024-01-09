#include <stdio.h>
int somme=0;

int sommeIntermediaire(int n);


int main()
{   
    int result = sommeIntermediaire(0);
    printf("La somme total est %d\n", result);
    return 0;
}

int sommeIntermediaire(int n)
{   
    char termine='o';
    
    printf("Entrez un nombre: ");
    scanf(" %d", &n);

    printf("Desirez-vous continuer ? (O/N):");
    scanf(" %c", &termine);

    if(termine=='o')
    {
        somme+=n;
        printf("\nla somme intermedaire est: %d\n", somme);
        return sommeIntermediaire(n);
    }else
    {
        return somme;
    }
}
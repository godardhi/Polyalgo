#include <stdio.h>
#include <stdbool.h>


void decomposeInteger(int b);
bool findStrongNumber(int n);
int factorial(int a);


// To be treated later : 
int arr[5];
int index=0;

int main()
{
    // 
    int n;
    printf("Enter a positve integer: ");
    scanf(" %d", &n);

    decomposeInteger(n);


    if(findStrongNumber(n)==1)
    {
        printf(" %d is a strong number\n",n);
    }
    else{
        printf(" %d is not a strong number\n",n);
    }

    return 0;
}


bool findStrongNumber(int n)
{
    int factorial_sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int i=0;
    while(i<size)
    {
        factorial_sum+=factorial(arr[i]);
        i++;
    }

    printf("%d\n", factorial_sum);

    return (factorial_sum==n) ? true:false;
}

int factorial(int a)
{ 
    if(a==0 || a==1)
    {
        return 1;
    }else
    {
        return  a*factorial(a-1);
    }    
}

void decomposeInteger(int b)
{
    if(b==0)
    {
        return;
    }else
    {
        int last_digit=b%10;
        arr[index]=last_digit;
        index++;
        b = b/10;
        decomposeInteger(b);
    }
}
#include <stdio.h>
#include <stdlib.h>

int simpleArraySum(int ar[], int n);

int main()
{
    //Lê quantidade de números do vetor
    int n; scanf("%d", &n);
    
    int numeros[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &numeros[i]);   
    }
    
    int soma = simpleArraySum(numeros, n);
    printf("%d\n", soma);

    return 0;
}

int simpleArraySum(int ar[], int n)
{
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += ar[i];
    }
    
    return soma;

}
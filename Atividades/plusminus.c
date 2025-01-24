#include <stdio.h>
#include <stdlib.h>

void plusMinus(int arr[], int n){
    
    //Declaração de contadores
    int c_positive = 0;
    int c_negative = 0;
    int c_zeros = 0;
    
    //Incrementar contadores com respectivos numeros
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            c_positive++;
        }
        else if(arr[i] < 0){
            c_negative++;
        }
        else{
            c_zeros++;
        }
    }
    
    //Calculo da proporção (Uso de Casting)
    float proportion_positives = (float)c_positive / n ;
    float proportion_negatives = (float)c_negative / n;
    float proportion_zeros = (float)c_zeros / n;

    printf("%f\n", proportion_positives);
    printf("%f\n", proportion_negatives);
    printf("%f\n", proportion_zeros);
}

int main(){
    //Lê o numero de elementos do vetor
    int n; scanf("%d", &n);

    //Declara o vetor
    int arr[n];

    //Aloca cada numero separado por espaço em um índice do vetor
    for(int i = 0;i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    //Chama a função plusMinus
    plusMinus(arr, n);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    //Usar acentos
    setlocale(LC_ALL, "");

    float valor1, valor2;
    printf("Informe o Primeiro Valor: ");
    scanf("%f", &valor1);
    printf("Informe o Segundo Valor: ");
    scanf("%f", &valor2);

    printf("A média dos valores é: %.2f\n", (valor1 + valor2)/2);

    return 0;
}
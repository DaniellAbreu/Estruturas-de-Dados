#include <stdio.h>
/*
scanf - Pega todo o input até aparecer espaço, \n, tab ou enter.
fgets/gets - Pega todo o input até aparecer \n
getchar - 


struct student {
    char name[20];
    int age, grade;
};

scanf("%s", aluno1.name);
printf("%s", aluno1.grade);

union

array - coleção de múltiplos valores do mesmo tipo de dados 
armazenados em localizações de memória consecutivas ** Como uma lista.

#include <stdio.h>
int main(){
   int arr[5];
   int i;
   for (i = 0; i <= 4; i++){
      printf("a[%d]: %d\n", i, arr[i]);
   }
   return 0;
}

int grades[ ]={50,56,76,67,43};

//O valor 5 representa a quantidade de linhas.
// O valor 2 representa a quantidade de colunas.

float marks2[5][2] = {{ 7.5, 6.8 }, { 6.5, 6.3 }, 
{ 5.7, 8.6 }, { 4.5, 5.8 }, { 3.6, 7.6 } };

divisão entre inteiros é inteiro

atoi
itoa

&& - and
|| - or 
! - not

else if()
switch()

Do 

While


*/ 
int main(){
   char ch;
   char word[10];
   int i = 0;
   printf("Enter characters. End by pressing the Enter key: ");
   while(1){
      ch = getchar();
      word[i] = ch;
      if (ch == '\n')
         break;
      i++;
   }
   printf("\nYou entered the word: %s", word);
   return 0;
}


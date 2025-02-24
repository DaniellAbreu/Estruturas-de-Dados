#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMEMAX 100
#define MENCAOMAX 2
#define TAM_MENCOES 6

typedef struct Aluno{
    char nome[NOMEMAX + 1];
    char mencao[MENCAOMAX + 1];
} Aluno;

const char* ordem_mencoes[] = {"SS", "MS", "MM", "MI", "II", "SR"};

int chave_mencao(Aluno* aluno1, Aluno* aluno2){
    int indice1 = -1;
    int indice2 = -1;
    
    for(int i = 0; i < TAM_MENCOES; i++){
        if(strcmp(aluno1->mencao, ordem_mencoes[i]) == 0){
            indice1 = i;
        }
        if(strcmp(aluno2->mencao, ordem_mencoes[i]) == 0){
            indice2 = i;
        }
    }

    if(indice1 == -1 || indice2 == -1){
        exit(1);
    }

    return indice1 - indice2;
}

int chave_nome(Aluno* aluno1, Aluno* aluno2){
    return strcmp(aluno1->nome, aluno2->nome);
}

int chave_dupla(Aluno* aluno1, Aluno* aluno2) {
    int resultado = chave_mencao(aluno1, aluno2);
    
    if (resultado == 0){
        return chave_nome(aluno1, aluno2);
    }

    return resultado;
}

void bubble_sort(Aluno* alunos[], int tamanho, int (*chave_sorteio)(Aluno*, Aluno*)){
    int i, j;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(chave_sorteio(alunos[j], alunos[j + 1]) > 0){
                Aluno* temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    Aluno* alunos[N];
    
    for(int i = 0; i < N; i++){
        alunos[i] = (Aluno*) malloc(sizeof(Aluno));
        if(!alunos[i]){
            return 1;
        }// Erro ao alocar mamória
        
        scanf("%s", alunos[i]->mencao);
        getchar();
        
        fgets(alunos[i]->nome, NOMEMAX + 1, stdin);
    }

    bubble_sort(alunos, N, chave_dupla);

    for(int i = 0; i < N; i++){
        printf("%s %s", alunos[i]->mencao, alunos[i]->nome);
        free(alunos[i]);
    }

    return 0;
}
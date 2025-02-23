#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Cria um nó, recebendo como parâmetro um dado do tipo inteiro e 
    retornando um ponteiro do tipo nó.
    Usado para acessar cada elemento da lista apontando para outros nós. */

Node* createNode(int data){
    Node* created_node = (Node *) malloc(sizeof(created_node));
    created_node->data = data;
    created_node->next = NULL;

    return created_node;
}

/* Cria uma lista vazia, retorna um ponteiro do tipo List
    Usado para acessar o número de elementos da lista e o primeiro ponteiro. */

List* createList(){
    List* list = (List *) malloc(sizeof(List));
    list->n_elem = 0;
    list->head = NULL;

    return list;
}

// Imprime cada elemento da lista na ordem primeiro->último.
void printList(List* list){
    Node* current_node = list->head;
    while (current_node != NULL)
    {
        printf("%d\n", current_node->data);
        current_node = current_node->next;
    }
    
}

// Adiciona elementos na lista sempre na primeira posição.
void addList(List* list, int data){
    Node* new_node = createNode(data);
    
    new_node->next = list->head;
    list->head = new_node;
    list->n_elem++;
    
}

int searchList(List* list, int data){
    Node* current_node = list->head;
    while(current_node->data != data){
        if(current_node->next == NULL){
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

void removeList(List* list, int data){
    /*if(searchList(list, data) == 1){
        printf("Nenhum nó encontrado para remoção\n");
        return;
    }
    */

    Node* current_node = list->head;
    Node* aux_node;
    while(current_node->data != data){
        if(current_node->next == NULL){
            printf("Nenhum nó encontrado para remoção\n");
            return;
        }
        aux_node = current_node;
        current_node = current_node->next;
    }

    aux_node->next = current_node->next;
    free(current_node);
}

// Libera toda a memória alocada dinâmicamente na criação de listas.
void freeList(List* list){
    Node* free_ptr;
    Node* aux_ptr = list->head;
    
    while(aux_ptr != NULL)
    {
        free_ptr = aux_ptr;
        aux_ptr = aux_ptr->next;
        free(free_ptr);
    }
    free(list);
}
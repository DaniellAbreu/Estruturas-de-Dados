#include <stdio.h>
#include <stdlib.h>

/* Definicao de estrutura do tipo No
   Usado para acessar os proximos nos e as informacoes contidadas neles.
*/
typedef struct node{
    int data;
    struct node* next;
} Node;

/* Definicao de estrutura de Lista inicial - 
   Usado para acessar o primeiro no e o numero de elementos da lista.
*/
typedef struct list{
    int n_elem;
    Node* head;
} SinglyLinkedListNode;

// Funcao que cria um no - Aloca memoria dinamicamente.
Node* createNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

// Funcao que cria uma lista - Aloca memoria dinamicamente.
SinglyLinkedListNode* createList(){
    SinglyLinkedListNode* list = (SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode));
    list->n_elem = 0;
    list->head = NULL;

    return list;
}

// Funcao que adiciona novos nos no final da lista - Aloca memoria dinamicamente.
void append(SinglyLinkedListNode* list, int data){
    Node* new_node = createNode(data);
    
    if(list->head == NULL){
        list->head = new_node;
        list->n_elem++;
    }

    else{
        Node* current_node = list->head;
        while(current_node->next != NULL){
            current_node = current_node->next;
        }

        current_node->next = new_node;
        list->n_elem++;
    }
}

// Funcao que imprime os elementos de uma lista.
void printList(SinglyLinkedListNode* list){
    Node* current_node = list->head;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Função que libera toda a memoria alocada dinamicamente.
void freeList(SinglyLinkedListNode* list){
    Node* aux_ptr = list->head;
    Node* free_ptr;
    while(aux_ptr != NULL){
        free_ptr = aux_ptr;
        aux_ptr = aux_ptr->next;
        free(free_ptr);
    }
    free(list);
}

// Funcao Principal - Deleta um no de uma dada posicao da lista.
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position){
    if(llist->head == NULL){
        return NULL;
    }

    if(position == 0){                                              
        Node* aux_node = llist->head;
        llist->head = aux_node->next;
        free(aux_node);
        
        llist->n_elem--;
        return llist;
    }

    Node* current_node = llist->head;
    for(int i = 0; i < position - 1 ; i++){
        current_node = current_node->next;
    }
    
    Node* aux_node = current_node->next;
    current_node->next = aux_node->next;

    free(aux_node);

    llist->n_elem--;
    return llist;
}

int main(){
    int n_elements, position;
    
    scanf("%d", &n_elements);

    SinglyLinkedListNode* list = createList();

    for(int i = 0; i < n_elements; i++){
        int info;
        scanf("%d", &info);
        append(list, info);
    }

    scanf("%d", &position);

    deleteNode(list, position);
    
    printList(list);

    freeList(list);

    return 0;
}
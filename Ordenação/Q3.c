#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//------------------------------------------------------------------------------

typedef struct Node{
    int info;
    struct Node* next;
} Node;

typedef struct List{
    int length;
    Node* head;
} List;

typedef struct Stack{
    int sum;
    Node* top;
} Stack;

//------------------------------------------------------------------------------

Node* create_node(int info){
    Node* node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;

    return node;
}

List* create_list(){
    List* list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->length = 0;

    return list;
}

Stack* create_stack(){
    Stack* stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->sum = 0;

    return stack;
}

//------------------------------------------------------------------------------

void append(List* list, int info){
    Node* new_node = create_node(info);

    if(list->head == NULL){
        list->head = new_node;
        list->length++;
        return;
    }
    
    Node* current_node = list->head;
    
    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;
    list->length++;
}

void remove_list(List* list, int info){
    // Não há elementos na lista;
    if(list->head == NULL){
        return;
    }
    
    Node* current_node = list->head;
    Node* aux_node = NULL;

    // Nó inicial removído; 
    if(current_node->info == info){
        list->head = current_node->next;
        free(current_node);
        list->length--;
        return;
    }

    // Caso geral;
    while(current_node->info != info){
        if(current_node->next == NULL){
            return;
        }
        aux_node = current_node;
        current_node = current_node->next;
    }

    aux_node->next = current_node->next;
    free(current_node);
    list->length--;
}

void print_list(List* list){
    Node* current_node = list->head;
    while (current_node != NULL)
    {
        if(current_node->next == NULL){
            printf("%d\n", current_node->info);
            return;
        }
        printf("%d ", current_node->info);
        current_node = current_node->next;
    }  
}

//------------------------------------------------------------------------------

void push(Stack* stack, int info){
    Node* new_node = create_node(info);
    
    new_node->next = stack->top;
    stack->top = new_node;
    stack->sum = stack->sum + info;
}

void print_stack(Stack* stack){
    Node* aux = stack->top;
    
    printf("[");
    while(aux != NULL){
      printf("%d", aux->info);
      if(aux->next != NULL){
        printf(", ");
      }
      aux = aux->next;
    }
    printf("]");
}

//------------------------------------------------------------------------------

int main(){
    int wookies;
    scanf("%d", &wookies);

    // Alocação de memória para lista de cargas;
    List* lista_cargas = create_list();

    while(TRUE){
        int carga;
        
        if(scanf("%d", &carga) == 1){
            append(lista_cargas, carga);
        }

        if(getchar() == '\n'){
            break;
        }
    }

    // Caso 1;
    if(wookies == 0){
        printf("Os Wookies foram para o lado sombrio da força!\n");
        print_list(lista_cargas);
        // Liberar memória!!!!!!!!!!!!
    }

    else{
        Stack* wookies_load[wookies];

        // Alocação de memória da pilha de cargas de cada Wookie;
        for(int i = 0; i < wookies; i++){
            wookies_load[i] = create_stack();
        }
        
        // Acrescentando cargas iniciais a cada Wookie;
        Node* current_node = lista_cargas->head;
        Node* aux = NULL;

        for(int i = 0; i < wookies; i++){
            if(lista_cargas->length == 0){
                break;
            }
            push(wookies_load[i], current_node->info);
            aux = current_node;
            current_node = current_node->next;
            remove_list(lista_cargas, aux->info);
        }

        ///*
        // Acrescentando Cargas a cada pilha de Wookies;
        current_node = lista_cargas->head;
        aux = NULL;

        while(current_node != NULL){
            for(int i = 0; i < wookies; i++){
                if(lista_cargas->length == 0){
                    break;
                }
                if(wookies_load[i]->top->info > current_node->info){
                    push(wookies_load[i], current_node->info);
                    aux = current_node;
                    current_node = current_node->next;
                    remove_list(lista_cargas, aux->info);
                    break;
                }
                if(i == wookies - 1){
                    aux = current_node;
                    current_node = current_node->next;
                    break;
                }
            }
        }
        //*/

        // Ordenando Wookies;

        
        // Imprimindo pilhas
        for(int i = 0; i < wookies; i++){
            print_stack(wookies_load[i]);
            if(i == wookies - 1){
                printf("\n");
                break;
            }
            printf(" ");
        }
        
        // Caso 2;
        if(lista_cargas->length == 0){
            printf("A força está com os Wookies!\n");
            // Liberar memória!!!!!!!!!!
            return 0;
        }

        print_list(lista_cargas);
        printf("%d\n", lista_cargas->length);
        // Liberar memória!!!!!!!!!!
    }
    
    return 0;
}
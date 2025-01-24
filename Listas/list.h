#ifndef __LIST_H__
#define __LIST_H__

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct list{
    int n_elem;
    Node* head;
} List;

Node* createNode(int data);

List* createList();

void printList(List* list);

void addList(List* list, int data);

int searchList(List* list, int data);

void removeList(List* list, int data);

void freeList(List* list);

#endif
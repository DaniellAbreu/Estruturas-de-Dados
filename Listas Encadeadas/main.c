#include <stdio.h>
#include "list.h"

int main(){
    List* list = createList();

    addList(list, 5);
    addList(list, 10);
    addList(list, 57);
    addList(list, 24);

    removeList(list, 12);
    int result = searchList(list, 10);
    printf("%d\n", result);

    printList(list);
    
    freeList(list);
    
    return 0;
}
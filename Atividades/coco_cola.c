#include <stdio.h>
#include <stdlib.h>
#define MAXCASE 11

int bottlesConvert(int empty_bottles){
    int full_bottles = 0;
    
    if (empty_bottles <= 1){
        return 0;
    }

    if (empty_bottles == 2){
        return 1;
    }

    full_bottles = (int)(empty_bottles / 3);
    
    /*Full bottles are consumed and turned into empty bottles plus the remainder (if any)*/
    empty_bottles = full_bottles + (empty_bottles % 3);

    /*Recurse call of function to sum each time empty bottles are divisable by 3*/
    return full_bottles + bottlesConvert(empty_bottles);
}

int main(){
    int empty_bottles[MAXCASE];

    int i = 0;
    do {
        scanf("%d", &empty_bottles[i]);
        i++;
    } while (i < MAXCASE && empty_bottles[i - 1] != 0);

    i = 0;
    while(i < MAXCASE && empty_bottles[i] != 0){
        int full_bottles = bottlesConvert(empty_bottles[i]);
        printf("%d\n", full_bottles);
        i++;
    }

    return 0;
}
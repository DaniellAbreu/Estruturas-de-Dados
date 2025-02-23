#include <stdio.h>
#include <stdlib.h>

void swapValue(int* i, int * j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quickSort(int array[], int low, int high){
    int pivot = array[high];
}

int main()
{
    int array[] = {1, 2 , 45, 10, 95, 12};
    int length = sizeof(array)/sizeof(int);
    int low = 0, high = length - 1;

    quickSort(array, low, high);
    swapValue(&array[0], &array[2]);

    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    

    return 0;
}

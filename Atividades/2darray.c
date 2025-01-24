#include <stdio.h>
#define ROWS 6
#define COLS 6

int hourglassSum(int arr[ROWS][COLS]){
    int current_sum;
    int max_sum = -63;

    for(int i = 0; i < ROWS - 2; i++){
        for(int j = 0; j < COLS - 2; j++){
             current_sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
             arr[i + 1][j + 1] +
             arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

            if(max_sum < current_sum){
                max_sum = current_sum;
            }
            
        }
    }
    
    return max_sum;
}

int main(){
    int arr[ROWS][COLS];

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int max_sum = hourglassSum(arr);

    printf("%d\n", max_sum);

    return 0;
}
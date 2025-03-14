#include <stdio.h>

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[9];
    int ins;
    int a, b, sum;
    int found = 0;
    scanf("%d", &arr[0]);
    for (int i=1; i<9; i++){
        scanf("%d", &arr[i]);
        for (int j=i; j>0; j--){
            if (arr[j-1]>arr[j]){
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
    
    for (a=0; a<9; a++){
        if (found) break;
        for (b=a+1; b<9; b++){
            if (found) break;
            sum = 0;
            for(int i=0; i<9; i++){
                if(i!=a&&i!=b) {
                 sum = sum + arr[i];
                }
            }
            if (sum == 100) {
                for (int j=0; j<9; j++){
                    if (j!=a&&j!=b) {printf("%d\n", arr[j]);}
                }
                found = 1;
                break;
            }
        }
    }
    
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int* harr = (int*)malloc(sizeof(int) * n);
    int* warr = (int*)malloc(sizeof(int) * n);
    int* rarr = (int*)malloc(sizeof(int) * n);
    for (int i=0; i<n; i++){
        rarr[i] = 1;
    }
    for (int i=0; i<n; i++){
        scanf("%d %d", &harr[i], &warr[i]);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (harr[i]<harr[j] && warr[i]<warr[j]){
                rarr[i]++;
            }
        }
    }
    for (int i=0; i<n-1; i++){
        printf("%d ", rarr[i]);
    }
    printf("%d", rarr[n-1]);
}
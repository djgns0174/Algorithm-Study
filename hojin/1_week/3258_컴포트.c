#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, Z, M, K = 0;
    int done = 0;
    int shouldIterate = 0;
    scanf("%d %d %d", &N, &Z, &M);
    int* Marr = (int*)malloc(sizeof(int)*M);
    for (int i=0; i<M; i++){
        scanf("%d", &Marr[i]);
    }
    
    while (!done && (K<N)){
        K++;
        shouldIterate = 1;
        for (int i=1; i<=N+1; i++){
            if (!shouldIterate) break;
            if (((K*i)%N+1) == Z ){
                shouldIterate = 0;
                done = 1;
                break;
            }
            else {
                for (int j=0; j<M; j++){
                    if (((K*i)%N+1) == Marr[j] ){
                        shouldIterate = 0;
                        break;
                    }
                }
            }
        }
    }
    printf("%d", K);
    
    return 0;
}
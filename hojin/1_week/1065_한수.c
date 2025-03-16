#include <stdio.h>

int main(){
    int n, cnt = 0;
    int hund, ten, one;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        hund = i/100;
        ten = (i%100)/10;
        one = i%10;
        
        if (hund){
            if ((hund-ten)==(ten-one)) cnt++;
        }
        else cnt++;
        
    }
    printf("%d", cnt);
    
    return 0;
}
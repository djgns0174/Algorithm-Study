#include<iostream>

using namespace std;

int main(void){

    int x;
    cin >> x;

    int dp[1000001] = {0,};
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=x; i++){
        int min = dp[i-1] + 1;
        if (i%3 == 0){
            int temp = dp[i/3] + 1;
            if(temp < min){
                min = temp;
            }
        }
        if(i%2 == 0){
            int temp  = dp[i/2] + 1;
            if(temp < min){
                min = temp;
            }
        } 
        dp[i] = min;
        // cout << i << " : " << dp[i] << "\n";
    }

    cout << dp[x] << "\n";
    
    return 0;
}
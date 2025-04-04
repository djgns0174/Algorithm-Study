#include <iostream>
#include <algorithm>

using namespace std;

static int dp[500][500];

int main(){
    int N, maxNum = 0;
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin >> dp[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(j==0) {
                dp[i][j] = dp[i-1][0] + dp[i][j];
            } else if (i==j) {
                dp[i][j] = dp[i-1][i-1] + dp[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1] + dp[i][j], dp[i-1][j] + dp[i][j]);
            }
            
            if(maxNum < dp[i][j]) maxNum = dp[i][j];
        }
    }
    
    cout << maxNum;
}
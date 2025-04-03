#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int RGB[N+1][3];
    int dp[N+1][3];
    for (int i=1; i<N+1; i++){
        for (int j=0; j<3; j++){
            cin >> RGB[i][j];    
        }
    }
    dp[1][0] = RGB[1][0];
    dp[1][1] = RGB[1][1];
    dp[1][2] = RGB[1][2];
    for (int i=2; i<=N; i++){
        for (int j=0; j<3; j++){
            dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + RGB[i][j];    
        }
        
    }
    int mincost = min(dp[N][0], dp[N][1]);
    mincost = min(mincost, dp[N][2]);
    cout << mincost;

    return 0;
}
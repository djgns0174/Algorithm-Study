#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int Warr[N+1];
    int Varr[N+1];
    int dp[N+1][K+1];
    memset(Warr, 1, sizeof(Warr));
    memset(Varr, 0, sizeof(Warr));
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=N; i++){
        cin >> Warr[i] >> Varr[i];
    }
    
    for (int i=1; i<=N; i++){
        for (int j=1; j<=K; j++){
            if (j < Warr[i]) {
                dp[i][j] = dp[i - 1][j];  
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Warr[i]] + Varr[i]);
            }
        }
    }
    
    cout << dp[N][K];
    
    return 0;
}
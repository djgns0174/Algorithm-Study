
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int Tarr[N+1];
    int Parr[N+1];
    int dp[N+2];
    
    for (int i=1; i<=N; i++){
        cin >> Tarr[i] >> Parr[i];
        dp[i] = 0;
    }
    dp[N+1] = 0;
    
    for (int i=N; i>0; i--){
        if (i+Tarr[i] > N+1){
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], Parr[i] + dp[i+Tarr[i]]);
        }
    }
    cout << dp[1];
    
    return 0;
}
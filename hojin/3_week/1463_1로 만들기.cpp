#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int X;
    cin >> X;
    vector<int> dp(X+1, 0);
    
    for (int i=2; i<=X; i++){
        dp[i] = dp[i-1] + 1;
        if ((i%3)==0){
            if (dp[i] > dp[i/3]+1) dp[i] = dp[i/3]+1;
        }
        if ((i%2)==0){
            if (dp[i] > dp[i/2]+1) dp[i] = dp[i/2]+1;
        }
    }
    
    cout << dp[X];

    return 0;
}
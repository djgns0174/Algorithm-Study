#include <iostream>

using namespace std;

static int dp[10001];
static int coin[101];

int main(){
    int N, K;
    cin >> N >> K;
    
    for(int i=1;i<=N;i++){
        cin >> coin[i];
    }
    

    dp[0] = 1;
    
    for(int i=1;i<=N;i++){
        int diff = coin[i];
        for(int j=diff;j<=K;j++){
            dp[j] += dp[j-diff];
        }
    }
    
    cout << dp[K];
}
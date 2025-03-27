#include <iostream>

using namespace std;

static int dp[1000000];

int main(){
    int N;
    cin >> N;
    
    dp[1] = 0;
    
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1] + 1; // -1을 한다면 이전 보다 한 번 횟수 증가
        if(!(i%2)) dp[i] = min(dp[i], dp[i/2]+1); // 2로 나누어 떨어지면
        if(!(i%3)) dp[i] = min(dp[i], dp[i/3]+1); // 3로 나누어 떨어지면
    }
    
    cout << dp[N];
}
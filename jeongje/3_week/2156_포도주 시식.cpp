#include <iostream>
#include <algorithm>

using namespace std;

static int glass[10001];
static int dp[10001];

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> glass[i];
    }
    
    dp[0] = 0;
    dp[1] = glass[1];
    dp[2] = glass[1] + glass[2];
    
    // ⚠️ 몰랐던 부분
    // dp[3] = dp[1] + glass[3] 또는 dp[2] 또는 dp[0] + glass[2] + glass[3] 중 최대값
    // dp[4] = dp[2] + glass[4] 또는 dp[3] 또는 dp[1] + glass[3] + glass[4] 중 최대값
    // 위 식을 토대로 밑에서 점화식 작성
    for(int i=3;i<=N;i++) {
        dp[i] = max({dp[i-2] + glass[i], dp[i-1], dp[i-3] + glass[i-1] + glass[i]});
    }
    
    cout << dp[N];
}
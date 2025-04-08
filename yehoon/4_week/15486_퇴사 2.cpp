#include<iostream>
#define endl "\n"

using namespace std;

int t[1500002] = {0,};
int p[1500002] = {0,};
int dp[1500002] = {0,};

/*
    퇴사 2

    dp값 : 현재값 까지의 최대금액

    dp[다음 상담 예정일] : dp값과 오늘금액을 더한값
    - 만약 현재값 이전에 최대 금액값이 있으면 최대금액값 + 오늘금액
    - 만약 dp[다음상담 예정일]값이 존재했을때(이전에 연산된값) cost값(최대금액값 + 오늘금액)과 비교

    [Ex]
    dp[4] = 10
    dp[7] = 20
    dp[4] = 10
    dp[5] = 30
        …
*/

int main(void){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }
    /*
        1번 접근법 -> 시간초과(n^2)
        dp[1][0] = p[1];
        dp[1][1] = 1 + t[1];
        for(int i=2; i<=n; i++){
            int nextDay = t[i] + i;
            dp[i][1] = nextDay;
            if(n+1 < nextDay) continue;

            int maxCost = 0;
            for(int j=1; j<=n; j++){
                if(dp[j][1] <= i){
                    maxCost = max(maxCost, dp[j][0]);
                }
            }

            dp[i][0] = maxCost + p[i];
        }

        int answer = 0;
        for(int i=1; i<=n; i++){
            answer = max(answer, dp[i][0]);
        }
        
        cout << answer << "\n";
    */

    int maxCost = 0;
    dp[1+t[1]] = p[1];
    for(int i=2; i<=n; i++){
        maxCost = max(maxCost, dp[i]);
        dp[i] = maxCost;

        int nextDay = i + t[i];
        if(nextDay > n+1) continue;

        int cost = dp[i] + p[i];
        dp[nextDay] = max(dp[nextDay], cost);

        // cout << "\n" << nextDay << " " << dp[nextDay] << "\n"; // test
    }

    int answer = 0;
    for(int i=1; i<=n+1; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer << endl; 

    return 0;
}
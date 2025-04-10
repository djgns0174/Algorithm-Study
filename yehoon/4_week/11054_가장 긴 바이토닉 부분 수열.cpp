#include<iostream>
#include<algorithm>

using namespace std;

/*
    가장 긴 바이토닉 부분 수열

    틀린이유 : dp 배열을 초기화 하지 않았다.

    오름차순과 내림차순 
    1 : 1 / 1
    5 :  1 5 / 1 5
    2 : 1 2 / 1 5 2
    1 : 1 / 1 5 2 1
    4 : 1 2 4 / 1 5 4
    3 : 1 2 3 / 1 2 4 3 or 1 5 4 3
    4 : 1 2 3 4 / 1 5 4
    5 : 1 2 3 4 5 / 1 2 3 4 5
    2 : 1 2 / 1 2 3 4 5 2
    1 : 1 / 1 2 3 4 5 2 1

    dp값을 2개로 둠
    하나는 오름차순 수열
    나머지는 내려오는 수열

    오름차순 수열을 생성할때는 본인보다 작은 수열의 이전값들중에서 가장 cost가 많은 수열에서 본인값 더함

    내려오는 수열을 생성할때는 본인보다 큰 수열의 이전값들중에서 가장 cost가 많은 수열에서 본인값 더함
*/

int main(void){

    int n;
    cin >> n;

    int arr[1001];

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int dp[1001][2] = {0,};
    dp[arr[1]][0] = 1;
    dp[arr[1]][1] = 1;

    for(int i=2; i<=n; i++){
        int maxCost = 0;

        for(int j=1; j<arr[i]; j++){
            if(dp[j][0] == 0) continue;
            maxCost = max(maxCost, dp[j][0]);
        }
        dp[arr[i]][0] = maxCost + 1;

        dp[arr[i]][1] = dp[arr[i]][0];
        maxCost = 0;
        for(int j=arr[i]+1; j<=1000; j++){
            if(dp[j][0] == 0) continue;
            maxCost = max(maxCost, dp[j][0]);
            maxCost = max(maxCost, dp[j][1]);
        }
        dp[arr[i]][1] = max(dp[arr[i]][1], maxCost + 1);
    }

    int answer = 0;
    for(int i=1; i<=n; i++){
        answer = max(answer, dp[arr[i]][1]);
        // cout << arr[i] << " " << dp[arr[i]][0] << " " << dp[arr[i]][1] << "\n"; //test
    }
    cout << answer << "\n";
    
    return 0;
}
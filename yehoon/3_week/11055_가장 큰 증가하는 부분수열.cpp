#include<iostream>
#include<algorithm>

using namespace std;

/*
    * 예시 * 
    1 100 2 50 60 3 5 6 7 8
    dp[1] : 1
    dp[100] : 101 (1, 100)
    dp[2] : 3 (1, 2)
    dp[50] : 53 (1, 2, 50)
    dp[60] : 113 (1, 2, 50, 60)

    * 설명 *
    arr에서 순서대로 dp값을 설정하는데 이때 dp값은 위와같이 해당 정수값이 마지막으로
    들어갔을때의 가장 큰 수열의 합이다. 
    이전값들(수열)중에서 해당값보다 작으면서 가장 dp값이 큰 것과 해당 값과 더해서 
    dp값을 설정한다.
*/

int main(void){

    int n;
    cin >> n;

    int arr[1001];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int dp[1001] = {0,};
    dp[arr[1]] = arr[1];
    for(int i=2; i<=n; i++){
        int maxNum = 0;
        for(int j=1; j<arr[i]; j++){
            if(dp[j] == 0) continue;

            maxNum = max(dp[j], maxNum);
        }

        dp[arr[i]] = maxNum + arr[i];
    }

    //정답출력
    int answer = dp[arr[1]];
    for(int i=2; i<=n; i++){
        answer = max(answer, dp[arr[i]]);
    }
    cout << answer << "\n";

    
    return 0;
}
#include<iostream>
#include<algorithm>

using namespace std;

/*
    dp 테이블을 2차원
    현재자리값과 이전자리값이 겹치지 않는 dp값 두개중에 작은것 하나를 선택해 현재값과 더함.
*/

int main(void){

    int n;
    cin >> n;
    int arr[1001][3];
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    int dp[1001][3];
    dp[1][0] = arr[1][0]; dp[1][1] = arr[1][1]; dp[1][2] = arr[1][2];
    for(int i=2; i<=n; i++){
        int minNum;
        for(int j=0; j<3; j++){
            switch(j){
                case 0:
                    minNum = min(dp[i-1][1], dp[i-1][2]);
                    break;
                case 1:
                    minNum = min(dp[i-1][0], dp[i-1][2]);
                    break;
                case 2:
                    minNum = min(dp[i-1][0], dp[i-1][1]);
                    break;
            }
            dp[i][j] = minNum + arr[i][j];   // 이전 dp값과 현재값 더하기
        }
    }

    int answer;
    answer = min(dp[n][0], dp[n][1]);
    answer = min(answer, dp[n][2]);

    cout << answer << "\n";

    return 0;
}
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

/*
    10 20 10 30 20 50
    dp[10] : 1 / path[10][1] = 10 
    dp[20] : 2 / path[20][2] = 10 20
    dp[10] : 1 / path[10][1] = 10
    dp[30] : 3 / path[30][3] = 10 20 30
    ...

    path에는 이전경로값들 모두 저장
    dp에는 최대 비용 저장

    시간복잡도 : o^2 으로 최대입력의 경우 1000 * 1000 = 1,000,000 통과가능

    * 틀린이유 *
    이전 경로값만 저장하려고 하였으나 덮어씌워지는 문제가 발생함
        반례 : 1 3 5 7 2 3
        정답 : 1 3 5 7 
        나의 답 : 1 2 3 5 7
    앞에 3의 이전경로값을 뒤의 3이 바꿔버려서 출력오류가 발생함.
*/

int main(void){

    int n;
    cin >> n;

    int arr[1001];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int dp[1001] = {0,};
    int path[1001][1000]; // 이전 경로값 저장
    dp[arr[1]] = 1;
    path[arr[1]][0] = arr[1];
    for(int i=2; i<=n; i++){

        int maxCost = 0;
        int maxNum = 0;
        for(int j=1; j<arr[i]; j++){
            if(dp[j] == 0) continue;
            if(maxCost <= dp[j]){
                maxCost = dp[j];
                maxNum = j;
            }
        }

        // 이전 경로값 저장
        for(int j=0; j<maxCost; j++){
            path[arr[i]][j] = path[maxNum][j];
        }
        path[arr[i]][maxCost] = arr[i];

        // dp 비용 값
        dp[arr[i]] = maxCost + 1;

        //test
        // cout << arr[i] << " : ";
        // for(int j=0; j<=maxCost; j++){
        //     cout << path[arr[i]][j] << " ";
        // }
        // cout << ": " << dp[arr[i]] << endl;
    }

    // 정답 첫째줄 출력
    int answerCost = 0;
    int answerIdx = 0;
    for(int i=1; i<=n; i++){
        if(answerCost < dp[arr[i]]){
            answerCost = dp[arr[i]];
            answerIdx = arr[i];
        }
    }
    cout << answerCost << "\n";

    // 정답 둘째줄 출력
    for(int i=0; i<answerCost; i++){
        if(i == answerCost-1) cout << path[answerIdx][i] << "\n";
        else cout << path[answerIdx][i] << " ";
    }

    return 0;
}
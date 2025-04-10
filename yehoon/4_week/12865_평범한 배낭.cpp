#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

/*
    dp : 2차원배열
    배낭 최대 무게가 주어졌을때 현재 자리값까지의 최대 가치값
    ex) dp[2][3] -> 배낭최대무게 3인 상태에서 2번째 물건까지 진행했을때 최대 가치값

    경우의 수 
    1. 배낭에 물건 넣는다
        dp[i][j] = max(dp[i-1][j], 현재물건가치 + dp[i-1][j-현재 물건의 무게])
        -> 이전 dp값과 현재 물건을 넣었을때의 dp값 비교

    2. 배낭에 물건을 넣지 않는다 
        dp[i][j] = dp[i-1][j] 
        -> 넣지 않으므로 이전값이 최대 가치값이 됨.
*/

struct Item {
    int weight;
    int value;
};

int dp[101][100001];

int main() {
    Item item[101];

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            int curWeight = item[i].weight;
            int curValue = item[i].value;

            if(curWeight > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], curValue + dp[i-1][j-curWeight]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}

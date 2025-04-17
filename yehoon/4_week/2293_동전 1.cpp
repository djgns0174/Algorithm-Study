#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

/*
    dp[k] = k원을 만들 수 있는 경우의 수

    [예시]
    동전 1 2 
    1. 먼저 1로 k원을 만들수 있는 경우의 수 나열
    1 2 3 4 5 6 7 8 9 10
    1 1 1 1 1 1 1 1 1 1

    2. 1과 2로 만들 수 있는 경우의 수 나열
    1 2 3 4 5 6 7 8 9 10
    1 2 1 1 1 1 1 1 1 1 -> 2는 동전2원으로 바로 만들수 있기 때문에 원래값 1에서 ++ 한다.
    1 2 2 3 3 4 4 5 5 6 -> 아래 설명 참고

    3원을 만들 수 있는 경우의 수는 1(3-2)에서 2원을 더해주면 되므로 dp[3] = dp[3] + dp[1]을 해주면 된다.
    4원을 만들 수 있는 경우의 수는 2(4-2)에서 2원을 더해주면 되므로 dp[4] = dp[4] + dp[2] 
    2의 경우의수에서 2를 더해주면 되므로 해당경로를 포함하고 원래dp값을 포함한 의미이다.
*/
int dp[10001] = {0,};
int coin[101] = {0,};

int main(void){


    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> coin[i];
    }

    
    for(int i=1; i<=n; i++){
        if(coin[i]>10001) continue;
        dp[coin[i]]++;
        for(int j=1; j<=k; j++){
            if(coin[i] > j) continue;
            dp[j] += dp[j-coin[i]];
        }
    }

    cout << dp[k] << endl;
}
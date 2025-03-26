#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;
    
    int arr[10001] = {0,};
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    // 연속 3잔 방지
    bool sequenceCheck = false;

    // dp 초기값 세팅
    int dp[10001];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = arr[1] + arr[3];
    if(dp[3] < dp[2]){
        dp[3] = dp[2];  // 틀린이유 -> dp[3]의 경우를 두가지만 생각했는데 3가지 경우를 생각해서 비교해야됨.
    }
    int tmp = arr[2] + arr[3];
    if(dp[3] < tmp){
        sequenceCheck = true;
        dp[3] = tmp;
    }

    if(n >= 4){
        for(int i=4; i<=n; i++){
            // 연속 세잔 마실 가능성이 있는 경우
            if(sequenceCheck){
                // 현재 잔을 마시는 경우
                dp[i] = dp[i-2] + arr[i];
                sequenceCheck = false;
                int tmp = dp[i-3] + arr[i-1] + arr[i];
                if(dp[i] < tmp) {
                    dp[i] = tmp;
                    sequenceCheck = true;
                    /* 
                        현재 잔을 마시는 경우
                        예제 케이스에서 dp[4]일때 25와 28 비교 필요
                    */
                }
                if(dp[i] < dp[i-1]){
                    dp[i] = dp[i-1];
                    /*
                        현재 잔을 안 마시는 경우
                        예제 케이스에서 dp[6]일때 33과 26 비교필요
                    */
                }
            } else {
                dp[i] = dp[i-1] + arr[i];
                sequenceCheck = true;

                int tmp = dp[i-2] + arr[i];
                if(dp[i] < tmp) {
                    dp[i] = tmp;
                    sequenceCheck = false;
                }
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
#include <iostream>

using namespace std;

static int dp[1001];
static int arr[1001];

int main(){
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]) { // 증가한다면
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    // for(int i=0;i<N;i++){
    //     cout << dp[i] << " ";
    // }
    
    int max = 0;
    for(int i=0;i<N;i++){
        if(dp[i] > max) max = dp[i];
    }
    
    cout << max;
}
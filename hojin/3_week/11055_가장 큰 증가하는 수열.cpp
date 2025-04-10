
#include <iostream>
using namespace std;

int main()
{
    int N, maxsum = 0;
    cin >> N;
    int arr[N+1];
    int dp[N+1];
    for (int i=1; i<N+1; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for (int i=1; i<N+1; i++){
        for (int j=1; j<i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+arr[i]);
            }
        }
        maxsum = max(maxsum, dp[i]);
    }
    
    cout << maxsum;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, maxlen = 0;
    int p;
    cin >> N;
    int arr[N+1];
    int dp[N+1];
    int largeindex[N+1];
    for (int i=1; i<N+1; i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for (int i=1; i<N+1; i++){
        for (int j=1; j<i; j++){
            if (arr[j] < arr[i]){
                if (dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    largeindex[i] = j;
                }
            }
        }
        if (maxlen < dp[i]){
            maxlen = dp[i];
            p = i;
        }
    }
    
    cout << maxlen << "\n";
    int tmparr[maxlen];
    tmparr[0] = arr[p];
    for (int i=1; i<maxlen; i++){
        tmparr[i] = arr[largeindex[p]];
        p = largeindex[p];
    }
    for (int i=maxlen-1; i>=0; i--){
        cout << tmparr[i] << " ";
    }
    
    return 0;
}
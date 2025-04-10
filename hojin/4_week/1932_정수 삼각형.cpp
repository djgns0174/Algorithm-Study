
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total = (n*(n+1))/2;
    vector<int> tri(total+1);
    vector<int> dp(total+1);
    for (int i=1; i<total+1; i++){
        cin >> tri[i];
        dp[i] = 0;
    }
    dp[1] = tri[1];
    int p = 1;
    int iter = 0;
    for (int i=1; i<=total-n; i++){
        dp[i+p] = max(dp[i+p], dp[i]+tri[i+p]);
        dp[i+p+1] = max(dp[i+p+1], dp[i]+tri[i+p+1]);
        iter++;
        if (p == iter){
            iter = 0;
            p++;
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = max(ans, dp[total-i]);
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> snack(n);
    int maxsnack = 0;
    int ans = 0;
    for (int i=0; i<n; i++){
        cin >> snack[i];
        maxsnack = max(snack[i], maxsnack);
    }
    sort(snack.begin(), snack.end());
    
    int start = 1;
    int end = maxsnack;
    while (start <= end){
        int mid = (start+end)/2;
        int snackcnt = 0;
        
        for (int i=0; i<n; i++){
            snackcnt += snack[i]/mid;
        }
        if (snackcnt >= m){
            ans = mid;
            start = mid +1;
        } else {
            end = mid -1;
        }
    }
    
    cout << ans;
    
    return 0;
}
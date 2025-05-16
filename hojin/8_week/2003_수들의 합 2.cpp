#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int start = 0;
    int end = 0;
    int sum = arr[0];
    
    while (start <= end){
        // cout << "sum: " << sum << " start: " << start << " end: " << end << '\n';
        if (sum == m) {
            cnt++;
            // cout << "cnt++! start: " << start << " end: " << end << '\n';
            sum -= arr[start++];
            if (end == n-1) break;
            sum += arr[++end];
        }
        else if (sum > m) {
            sum -= arr[start++];
            if (start-1==end) {
                if (end == n-1) break;
                sum += arr[++end];
            }
        }
        else {
            if (end == n-1) break;
            sum += arr[++end];
        }
        
    }
    
    cout << cnt;

    return 0;
}
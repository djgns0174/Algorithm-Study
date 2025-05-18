#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    
    
    vector<int> arrcnt(200001, 0);
    int start = 0;
    int end = 0;
    int len = 1;
    int maxlen = 1;
    arrcnt[arr[0]]++;

    while (end < n-1){
        if (arrcnt[arr[end+1]]+1 <= k){
            end++;
            arrcnt[arr[end]]++;
            len++;
        } else {
            arrcnt[arr[start]]--;
            start++;
            len--;
        }
        // cout << "start: " << start << ", end: " << end << ", len: " << len << '\n';
        maxlen = max(maxlen, len);
    }

    cout << maxlen;

    return 0;
}
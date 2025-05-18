#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n+1);
    arr[n] = 0;
    for (int i=0; i<n; i++) cin >> arr[i];
    int len = 1;
    int minlen = n+1;
    int start = 0;
    int end = 0;
    int sum = arr[0];

    while (end < n){
        if (sum >= s){
            minlen = min(minlen, len);
            sum -= arr[start++];
            len--;
            if (start>end){
                end = start;
                len=1;
            }
        } else {
            sum += arr[++end];
            len++;
        }
        // cout << "start: " << start << ", end: " << end << ", len: " << len << '\n';
    }

    if (minlen == n+1) minlen = 0;

    cout << minlen;

    return 0;
}
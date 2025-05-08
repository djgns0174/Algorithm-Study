#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1001];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    vector<int> subvec;
    int answer = -1;
    bool found = false;

    for (int i=n-1; i>=0; i--) {
        for (int j=i-1; j>=0; j--) {
            int sub = arr[i]-arr[j];
            if (sub<0 || binary_search(subvec.begin(), subvec.end(), sub)) continue;

            for (int k=0; k<=j; k++) {
                int f = sub-arr[k];
                if (binary_search(arr, arr+j+1, f)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answer = arr[i];
                break;
            } else {
                subvec.push_back(sub);
                sort(subvec.begin(), subvec.end());
            }
        }
        if (found) break;
    }

    cout << answer;
    return 0;
}

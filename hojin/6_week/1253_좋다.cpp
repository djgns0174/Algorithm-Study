#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int goodcnt = 0;
    
    for (int i=0; i<n; i++){
        int start = 0;
        int end = n-1;
        
        while (start < end){
            if (start == i) {
                start++;
                continue;
            }
            if (end == i) {
                end--;
                continue;
            }
            
            int add = arr[start] + arr[end];
            if (add == arr[i]){
                goodcnt++;
                break;
            } else if (add > arr[i]) {
                end--;
            }
            else {
                start++;
            }
        }
    }
    
    cout << goodcnt;
    
    return 0;
}
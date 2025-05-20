#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// O(N^3)은 시간초과
// O(N^2logN) 안에서 해결을 봐야된다. 

int main(){
    int N;
    cin >> N;
    
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int ans = INT_MAX;
    int left, right;
    for(int i=0;i<N-2;i++){
        for(int j=i+3;j<N;j++){
            left = i+1;
            right = j-1;
            
            int sum1 = v[i] + v[j];
            
            while(left<right) {
                int sum2 = v[left] + v[right];
                int diff = abs(sum2 - sum1);
                
                ans = min(ans, diff);
                if(diff == 0) {
                    cout << 0;
                    return 0;
                }
                if(sum2 > sum1) right--;
                else left++;
            }
        }
    }
    
    cout << ans;

}
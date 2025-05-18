#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, S;
    cin >> N >> S;
    
    vector<int> v(N);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    int left = 0, right = 0, sum = 0;
    int len = 100001;
    
    while(right < N) {
        sum += v[right];
        
        while(sum >= S) {
            len = min(len, right - left + 1);
            sum -= v[left];
            left++;
        }
        
        right++;
        
    }
    
    if(len == 100001) cout << 0;
    else cout << len;
}
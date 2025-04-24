#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    
    vector<int> v(N);
    
    int mx = -1;
    for(int i=0;i<N;i++){
        cin >> v[i];
        if(mx < v[i]) mx = v[i];
    }
    
    
    int left = 1;
    int right = mx;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        
        long long cnt = 0;
        for(int i=0;i<N;i++){
            if(v[i] < mid) continue;
            
            cnt += (v[i] / mid);
        }
        
        
        if(M <= cnt) {  // feasible
            left = mid + 1;
            ans = mid;
        } else {  // infeasible
            right = mid - 1;
        }
        
        
    }
    
    cout << ans;
}
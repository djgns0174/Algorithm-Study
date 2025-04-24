#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N, M, L;
    cin >> N >> M >> L;
    
    vector<int> v(N+2);
    
    v[N] = 0;
    v[N+1] = L;
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int left = 1;
    int right = L;
    int ans = 1000;
    while(left <= right) {
        int sum = 0;
        int mid = (left + right) / 2;
        
        for(int i=1;i<v.size();i++){
            
            int distance = v[i] - v[i-1];
            
            int cnt = distance / mid;
            
            if(cnt > 0) {
                if(distance % mid == 0) {
                    sum += cnt - 1;
                } else {
                    sum += cnt;
                }
            }
        }
        
        
        if(sum > M) {
            left = mid + 1;
        } else { 
            // sum <= M 인 상황
            // sum이 M이랑 같으면 직관적으로 okay고
            // sum이 M보다 작은 경우도 아직 설치를 다 못했지만
            // 현재 mid로 최대값의 최소는 되었으니 다른 곳에 남은 휴게소를 추가 설치하면 되므로(다른 구간에 추가 설치해도 최대값의 최소는 바뀌지 않는다)
            // sum < M 인 경우도 feasible 하다 
            right = mid - 1;
            ans = (mid > ans ? ans : mid);
        }
    }
    cout << ans;
    
}
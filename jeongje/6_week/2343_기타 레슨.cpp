#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N);
    
    int left = 0;
    int right = 0;
    for(int i=0;i<N;i++){
        cin >> v[i];
        if(left < v[i]) left = v[i]; // 시작은 원소들 중 최대 값
        right += v[i]; // 끝은 원소들의 전체 합 
    }
    
    
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        int count = 0;
        int sum = 0;
        for(int i=0;i<N;i++){
            if(sum + v[i] > mid) {
                count++;
                sum = 0;
            }
            sum += v[i];
        }
        
        if(sum > 0) count++;
        
        if(count > M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    
    cout << left;
}
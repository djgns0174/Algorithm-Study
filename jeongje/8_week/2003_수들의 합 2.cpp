#include <iostream>
#include <algorithm>

using namespace std;

static int arr[10000];

int main(){
    int N, M;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = arr[0];
    
    
    while(left <= right && right < N) {
        if(sum < M){
            right++;
            sum += arr[right];
        } else if (sum > M) {
            sum -= arr[left];
            left++;
            
            if(left > right) {  // ★ 개별 하나의 원소가 M보다 큰 경우에 left가 right를 넘어감 
                right++;
                sum = arr[right];
            }
            
        } else {  // sum == M
            sum -= arr[left];
            left++;
            cnt++;
            
            
            if(left > right) {  // ★ 개별 하나의 원소가 M인  경우 left가 right를 넘어감 
                right++;
                sum = arr[right];
                
            }
            
        }
    }
    
    cout << cnt;
}
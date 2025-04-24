/*
N의 최대 개수는 10,000 개 && 시간 제한은 1초
최대 시간 복잡도는 O(N^2) 

*/


#include <iostream>
#include <algorithm>

using namespace std;

static int arr[10000];

int main(){
    int N, M;
    cin >> N;
    
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    cin >> M;
    
    sort(arr, arr + N);

    if(sum <= M){ // 예산이 딱 맞거나 충분한 경우 
        cout << arr[N-1];
    } else {  // 예산이 부족한 경우 (상한액 책정 필요)
        
        int left = 1; // ⚠️ left = arr[0] 하면 틀림 
        int right = arr[N-1];
        int mid;
        int ans = arr[0];
        while(left <= right){
            mid = (left + right) / 2;
            
            int sum = 0;
            for(int i=0;i<N;i++){
                if(arr[i] < mid) {
                    sum += arr[i];
                } else {
                    sum += mid;
                }
            }
            
            if(sum <= M) { // feasible
                left = mid + 1;
                ans = mid;
            } else { // infeasible 
                right = mid - 1;
            }
            
            
        }
        
        
        cout << ans;
    }
    
    
    
}
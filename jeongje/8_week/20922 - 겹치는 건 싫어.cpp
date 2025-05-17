#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N);
    vector<int> check(100001, 0);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    int result = 1;
    
    int left = 0;
    int right = 1;
    check[v[left]]++;
    
    while(right <= N-1) {
        if(check[v[right]] < K) { // 같은 정수가 K개 미만 
            check[v[right]]++;
        } else { // 같은 정수가 K개 이상 
            while(v[left] != v[right]) {
                check[v[left]]--;
                left++;
            }
            left++;
        }
        
        int tmp = right - left + 1;
        
        result = max(result, tmp);
        
        right++;
    }
    
    cout << result;
}
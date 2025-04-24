#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// N의 최대 개수가 1000 이므로
// O(N^2·logN) 으로 해결할 수 있다.

static vector<int> twoSum;

bool binary_search(int target);

int main(){
    int N;
    cin >> N;

    vector<int> v(N);

    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){ // x, y, z가 같을 수 있으므로 j 는 i부터 시작해야 같은 수를 두 번 더할 수 있다.
            twoSum.push_back(v[i] + v[j]);
        }
    }
    
    sort(v.begin(), v.end());
    sort(twoSum.begin(), twoSum.end());
    
    
    for(int i=N-1;i>-1;i--){
        for(int j=i;j>-1;j--){
            int target = v[i] - v[j];
            bool find = binary_search(target);
            
            if(find) {
                cout << v[i];
                return 0;
            }
        }
    }
}

bool binary_search(int target) {
    int left = 0;
    int right = twoSum.size() - 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(twoSum[mid] == target) return true;
        
        if(twoSum[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    
    return false;
}
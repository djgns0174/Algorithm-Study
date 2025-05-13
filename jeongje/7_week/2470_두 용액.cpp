#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> v(N);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int left = 0;
    int right = N-1;
    
    int min = 2000000000;
    
    int liquid1, liquid2;
    while(left < right){
        int sum = v[left] + v[right];
        
        if(abs(sum) < min) {
            min = abs(sum);
            liquid1 = v[left];
            liquid2 = v[right];
            
            if(min == 0) break;
        }
        
        if(sum < 0) {
            left++;
        } else {
            right--;
        }
        
    }
    
    cout << liquid1 << " " << liquid2;
}
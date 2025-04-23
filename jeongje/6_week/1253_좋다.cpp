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
    
    int count = 0;
    
    for(int i=0;i<N;i++){
        int target = v[i];
        
        int left = 0;
        int right = N-1;
        
        // 전형적인 투포인터 
        while(left < right) {
            if(v[left] + v[right] == target) {
                if(left != i && right != i) {
                    count++; 
                    break;
                }
                else if(left == i) {
                    // -5 -3 -2 -1 0 1 2 3 
                    // target이 -3이고 left가 -3 rigth가 0 인 경우 GOOD이 아니다
                    // 탐색을 멈추면 안되는 이유는 -2 , -1 로 GOOD이 될 수 있기 떄문에
                    // left++로 전진해야된다. 
                    left++;
                } else if(right == i) {
                    right--;
                } 
            } else if (v[left] + v[right] < target) {
                left++;
            } else {
                right--;
            }
            
        }
    }
    
    cout << count;
}
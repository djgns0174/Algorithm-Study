#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 이분탐색 시도하다가 잘 안돼서 두 포인터로 풀어버림
int main()
{
    int n;
    cin >> n;
    vector<int> liquid(n);
    for (int i=0; i<n; i++){
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end());
    
    int start = 0;
    int end = n-1;
    int ans1 = start;
    int ans2 = end;
    int mix;
    int premix = liquid[start] + liquid[end];
    
    while (start < end) {
        
        mix = liquid[start] + liquid[end];
        // cout << "start: " << start << ' ' << "end: " << end << '\n';
        
        if (mix > 0){
            
            if (abs(premix) > abs(mix)){
                // cout << "premix: " << premix << ", mix: " << mix << '\n';
                ans1 = start;
                ans2 = end;
                premix = mix;
            }
            end--;
            //cout << "\nans1: " << ans1 << "\n*ans2*: " << ans2;
        } else if (mix < 0){
            // cout << "premix: " << premix << ", mix: " << mix << '\n';
            if (abs(premix) > abs(mix)){
                ans1 = start;
                ans2 = end;
                premix = mix;
            }
            start++;
            //cout << "\nans1: " << ans1 << "\nans2: " << ans2;
        } else {
            ans1 = start;
            ans2 = end;
            //cout << "\nans1: " << ans1 << "\nans2: " << ans2;
            break;
        }
    }
    
    cout << liquid[ans1] << ' ' << liquid[ans2];
    // cout << "\nans1: " << ans1 << "\nans2: " << ans2;
    
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int lecture[n];
    int totalsum = 0;
    int maxlecture = 0;
    for (int i=0; i<n; i++){
        cin >> lecture[i];
        totalsum += lecture[i];
        maxlecture = max(maxlecture, lecture[i]);
    }
    
    int start = maxlecture;
    int end = totalsum;
    int mid;
    int answer = totalsum;

    while(start <= end){
        
        mid = (start+end)/2;

        int count = 1;
        int sum = 0;
        
        for (int i=0; i<n; i++) {
            if (sum + lecture[i] > mid) {
                count++;
                sum = lecture[i];
            } else {
                sum += lecture[i];
            }
        }
        
        if (count <= m) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        
    }
    
    
    cout << answer;

    return 0;
}
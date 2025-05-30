#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int main() {
    int n;
    cin >> n;
    int average, median;
    int mode = 0;
    int range;

    int sum = 0;

    int maxFreq = 0;
    bool isSecondSmall = false;

    vector<int> arr(n);
    vector<int> arrFreq(8001, 0); // 빈도수 저장

    for(int i=0; i<n; i++){
        cin >> arr[i];

        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){ // 최빈값
        arrFreq[arr[i]+4000]++;
        if (arrFreq[arr[i]+4000] > maxFreq){ // 최빈값이 처음 등장
            maxFreq = arrFreq[arr[i]+4000];
            mode = arr[i];
            isSecondSmall = false;
        }
        else if (arrFreq[arr[i]+4000] == maxFreq && !isSecondSmall){ // 빈도가 같은 값이 두 번 등장
            mode = arr[i];
            isSecondSmall = true;
        }
    }

    average = (int)((float)sum/(float)n + (sum > 0 ? 0.5 : -0.5));
    
    median = arr[n/2];

    range = arr[n-1] - arr[0];

    
    cout << average << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

    return 0;
}


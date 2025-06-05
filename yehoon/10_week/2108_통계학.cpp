#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <cmath> 
#include<set>

#define endl "\n"

using namespace std;

int main(void)
{
    int n; cin >> n;

    map<int,int> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    // 합 구하기
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        m[arr[i]]++;
    }

    // 평균, 중앙값, 범위 구하기
    int average = round((double) sum / n);
    int median = arr[n/2];
    int range = arr[n-1] - arr[0];

    // 최빈값 구하기
    int temp = 0;
    int mode;
    set<int>modes;
    for(const auto &pair : m)
    {
        if(temp < pair.second) {
            temp = pair.second;
            mode = pair.first;
        }
    }
    modes.insert(mode);
    // 중복되는 최빈값 넣기
    for(const auto &pair : m)
    {
        if(m[mode] == pair.second) modes.insert(pair.first);
    }

    // 출력
    cout << average << endl << median << endl ;
    if(modes.size() > 1) 
    {
       modes.erase(modes.begin());
       cout << *modes.begin() << endl;
    }
    else cout << *modes.begin() << endl;
    cout << range << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s;
    int t;
    vector<pair <int, int>> lecture(n);
    for (int i=0; i<n; i++){
        cin >> s >> t;
        lecture[i].first = s;
        lecture[i].second = t;
    }
    
    sort(lecture.begin(), lecture.end());
    
    priority_queue<int, vector<int>, greater<int>> roomt;
    
    roomt.push(lecture[0].second);
    
    for (int i=1; i<n; i++){
        if (lecture[i].first >= roomt.top() ){
            roomt.pop();
        }
        roomt.push(lecture[i].second);
    }
    
    cout << roomt.size();
    
    return 0;
}
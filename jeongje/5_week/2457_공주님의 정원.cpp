#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for(int i=0;i<N;i++){
        int start_month, start_day, end_month, end_day;
        cin >> start_month >> start_day >> end_month >> end_day;

        v.push_back({start_month*100 + start_day, end_month*100+end_day});
    }

    sort(v.begin(), v.end()); // 개화 시기가 빠른 순으로 정렬

    int start = 301;
    int end = 0;
    int count = 0;

    int i=0;
    for(; start<=1130 ;){
        bool find = false;
        
        for(i;i<N;i++){
            if(v[i].first <= start) {
                if(end < v[i].second) {
                    find = true;
                    end = v[i].second;
                }
            } else {
                break;
            }
        }

        if(!find){
            cout << 0;
            return 0;
        }

        count++;
        start = end;
    }

    cout << count;


}
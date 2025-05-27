#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

static int N;
static vector<int> v;
static map<int, int> m;

int calMean(); // 산술 평균 구하기
int calMedian(); // 중앙값 구하기
int calMode(); // 최빈값 구하기
int calRange(); // 범위 구하기

bool cmp(pair<int, int> &a, pair<int, int> &b);

int main(){
    cin >> N;
   
    v.resize(N);
   
    for(int i=0;i<N;i++){
        cin >> v[i];
       
        if(m.find(v[i]) == m.end()) {
            m.insert({v[i], 1});
        } else {
            m[v[i]]++;
        }
       
    }
   
    sort(v.begin(), v.end());
   
    cout << calMean() << "\n";
    cout << calMedian() << "\n";
    cout << calMode() << "\n";
    cout << calRange() << "\n";
   
    return 0;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int calMean() {  // 산술 평균 구하기
    double sum = 0;
    for(int i=0;i<N;i++){
        sum += v[i];
    }
   
    return int(round(sum / N));
}

int calMedian() {  // 중앙값 구하기
    return v[N / 2];
}

int calMode() {    // 최빈값 구하기
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    if(v.size() == 1) {
        return v[0].first;
    } else {
        if(v[v.size()-1].second == v[v.size()-2].second) {
            int count = 0;
            for(int i=0;i<v.size();i++){
                if(v[i].second == v[v.size()-1].second){
                    count++;
                }
                if(count == 2) {
                    return v[i].first;
                }
            }
        } else {
            return v[v.size()-1].first;
        }
    }
    
    return 0;
}

int calRange(){    // 범위 구하기
    return v[N-1] - v[0];
}
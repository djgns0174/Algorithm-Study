#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<pair<int,int>> v(N);
    
    for(int i=0;i<N;i++){
        int start, end;
        cin >> start >> end;
        v[i] = {start, end};
    }
    
    sort(v.begin(), v.end()); // 가장 빨리 시작하는 수업순으로 정렬
    
    priority_queue<int, vector<int>, greater<int>> pq; // 가장 빨리 끝나는 수업들이 앞에 위치하는 우선순위 큐 
    
    pq.push(v[0].second);
    
    for(int i=1;i<N;i++){
        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        } else {
            pq.push(v[i].second);
        }
    }
    
    
    cout << pq.size(); // 우선순위 큐의 사이즈 == 강의실의 개수 
}
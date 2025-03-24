#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, K;
static bool visited[100001];
static int dx[2] = {-1 ,1};

void BFS(int start);

int main(){
    cin >> N >> K;
    
    BFS(N);
    
}


void BFS(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(visited[now]) continue;
        visited[now] = true;
        
        if(now == K) {
            cout << cnt;
            return;
        }
        
        
        for(int i=0;i<3;i++){
            int next_x;
            if(i==2) {
                next_x = now * 2;
            } else {
                next_x = now + dx[i];
            }
            
            
            if(next_x > -1 && next_x <100001 && !visited[next_x]) {
                if(i==2){
                    pq.push({cnt, next_x});
                } else {
                    pq.push({cnt + 1, next_x});
                }
            }
            
        }
        
    }
}
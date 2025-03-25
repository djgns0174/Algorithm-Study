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
    
    if(N==K) {
        cout << 0;
    } else {
        BFS(N);
    }
    
}


void BFS(int start) {
    visited[start] = true;
    queue<pair<int, int>> que;
    que.push({start, 1});
    
    while(!que.empty()){
        int now = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        for(int i=0;i<3;i++){
            int next_x;
            if(i==2) {
                next_x = now * 2;
            } else {
                next_x = now + dx[i];
            }
            
            if(next_x > -1 && next_x <100001 && !visited[next_x]) {
                que.push({next_x, cnt+1});
                visited[next_x] = true;
                if(next_x == K) {
                    cout << cnt;
                    return;
                }
            }
        }
    }
}
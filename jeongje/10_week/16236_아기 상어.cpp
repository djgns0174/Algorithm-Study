#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

static int map[20][20];
static bool visited[20][20];
static bool found;

int N, shark_size, start_i, start_j, total_time;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void BFS(int i, int j);

int main() {
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            
            if(map[i][j] == 9) {
                start_i = i;
                start_j = j;
                
                map[i][j] = 0;
            }
        }
    }
    
    shark_size = 2;
    int eat_cnt = 0;
    
    do {
        found = false;
        fill(visited[0], visited[N], false);
        
        if(eat_cnt == shark_size) {
            shark_size++;
            eat_cnt = 0;
        }
        
        BFS(start_i, start_j);
        
        map[start_i][start_j] = 0;
        
        eat_cnt++;
        
    } while(found);
    
    
    cout << total_time;
}


void BFS(int i, int j) {
    visited[i][j] = true;
    
    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});
    
    int temp;

    while(!q.empty()) {
        auto[now_i, now_j, cnt] = q.front();
        
        
        
        if(map[now_i][now_j] > 0 && map[now_i][now_j] < shark_size && temp == cnt) {
            if((start_i > now_i) || (start_i == now_i && start_j > now_j)) {
                start_i = now_i;
                start_j = now_j;
                
                continue;
            }
        }
        q.pop();
        

        for(int d=0;d<4;d++){
            int next_i = now_i + di[d];
            int next_j = now_j + dj[d];
            
            if((!visited[next_i][next_j]) && (next_i < N) && (next_i > -1)  && (next_j < N) && (next_j > -1)) {
                if(map[next_i][next_j] <= shark_size) 
                {
                    if(map[next_i][next_j] > 0 && map[next_i][next_j] < shark_size && !found) {
                        found = true;
                        start_i = next_i;
                        start_j = next_j;
                        temp = cnt + 1;
                        total_time += temp;
                    }
                    else 
                    {
                        q.push({next_i, next_j, cnt + 1});
                        visited[next_i][next_j] = true;
                    }
                }
            }
            
        }
    }
}


// 본 코드의 86번 라인 밑을 아래 처럼 바꾸면 안되는데 아직 이유를 모르겠음
// 머리가 너무 아파서 나중에 디버깅할 예상 


// if((!visited[next_i][next_j]) && (next_i < N) && (next_i > -1)  && (next_j < N) && (next_j > -1)) {
//     if(map[next_i][next_j] == 0) { // 물고기가 없는 곳 
//         q.push({next_i, next_j, cnt + 1});
//         visited[next_i][next_j] = true;
        
//     } else { // 물고기가 존재하는 곳 
//         if(map[next_i][next_j] < shark_size && !found) { // 먹을 수 있는 경우 
//             start_i = next_i;
//             start_j = next_j;
            
//             found = true;
            
//             temp = cnt + 1;
//             total_time += temp;

            
//         } else  { // 먹지는 못하지만 지나갈 수는 있는 경우 || 이미 먹은 경우 (found = true)
//             q.push({next_i, next_j, cnt + 1});
//             visited[next_i][next_j] = true;
            
//         }
//     }
// }
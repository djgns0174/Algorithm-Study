#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int mat[50][50];
int visited[50][50];
int answer;

struct point{ // 좌표 구조체
    int x;
    int y;
};

void bfs(int x, int y, int M, int N){
    queue<point> q;
    point p;
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, -1, 1}; // 인접노드 상하좌우 탐색
    
    p.x = x;
    p.y = y;
    q.push(p);
    visited[x][y] = 1;
    while (!q.empty()){
        p = q.front();
        x = p.x;
        y = p.y;
        q.pop();
        for (int i=0; i<4; i++){
            if ((x+dx[i] < 0) || (x+dx[i] > M-1) || (y+dy[i] < 0) || (y+dy[i] > N-1) ){ // 인접 노드 배열 인덱스 조건
                continue;
            } else if (!visited[x+dx[i]][y+dy[i]] && mat[x+dx[i]][y+dy[i]]) {
                p.x = x+dx[i];
                p.y = y+dy[i];
                visited[p.x][p.y] = 1;
                q.push(p);
            }
        }
    }
    answer++;
};

int main() {
    
    int x, y;
    int T, M, N, K;
    cin >> T;
    
    while(T){
        cin >> M >> N >> K;
        vector<point> cabbage(K); // 배추 좌표 배열
        answer = 0;
        memset(mat, 0, sizeof(mat));
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<K; i++){ // 배추 좌표 저장
            cin >> x >> y;
            mat[x][y] = 1;
            cabbage[i].x = x;
            cabbage[i].y = y;
        }
        for (int i=0; i<K; i++){ // 배추 좌표에 한해 bfs
            x = cabbage[i].x;
            y = cabbage[i].y;
            if (!visited[x][y]){
                bfs(x, y, M, N);  
            } 
        }
        cout << answer << endl;
        T--;
    }
    
    return 0;
}
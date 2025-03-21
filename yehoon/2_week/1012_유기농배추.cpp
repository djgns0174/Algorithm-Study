#include<iostream>
#include<queue>

using namespace std;

queue<pair<int, int> > q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int t, m, n, k;

// 방문표시
bool visited[50][50];
        
// 배추 맵
int cabbage[50][50];

void push(int y, int x){
    pair<int, int> temp;
    temp.first = y; temp.second = x;
    q.push(temp);
    //방문 처리
    visited[y][x] = true;
}

// 배추를 큐에 넣고 큐가 빌때까지 인접한 배추를 찾는다. 그리고 그 영역을 다 찾으면 answer++
void bfs(){
    while(!q.empty()){
        int cabbage_y = q.front().first;
        int cabbage_x = q.front().second;
        q.pop();
        
        // 틀린 이유 -> 방문에 상관없이 큐에 쌓이기 때문
        // //방문 처리
        // visited[cabbage_y][cabbage_x] = true;

        for(int i=0; i<4; i++){
            
            int ny = cabbage_y + dy[i];
            int nx = cabbage_x + dx[i];

            //범위 검사
            if(ny < 0 || nx < 0 || nx >= m || ny >= n) continue;

            if(cabbage[ny][nx] == 1 && !visited[ny][nx]){
                push(ny, nx);
            }
        }
    }
}

int main(void){

    cin >> t;

    for(int z=0; z<t; z++){

        int answer = 0;

        cin >> m >> n >> k;

        // 초기화
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                cabbage[i][j] = 0;
                visited[i][j] = false;
            }
        }

        // 배추 맵에 표시
        for(int i=0; i<k; i++){
            int cabbage_x, cabbage_y;
            cin >> cabbage_x >> cabbage_y;
            cabbage[cabbage_y][cabbage_x] = 1;
        }

        // 핵심로직
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                
                // 배추가 있고 방문하지 않았다면
                if(cabbage[y][x] == 1 && !visited[y][x]){
                    push(y, x);
                    bfs();
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}
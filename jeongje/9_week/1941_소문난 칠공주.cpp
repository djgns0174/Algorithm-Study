#include <iostream>
#include <queue>

using namespace std;

static char arr[5][5];
static bool visited[5][5];
static bool chosen[25];
static int result;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void DFS(int start, int count);
bool isValid();

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
   
   
    DFS(0, 0);
   

    cout << result;
}

void DFS(int start, int count) {
    if(count == 7) { // 7명 결성 완료
        if(isValid()) result++; // 다솜파 4명 이상인지 + 상하좌우 연결되었는지
    }
   
    for(int i=start;i<25;i++){ // 25개의 자리 중 7개를 조합
        if(chosen[i]) continue;
        chosen[i] = true;
        DFS(i, count + 1);
        chosen[i] = false;
    }
}

bool isValid() {
    int dasom_cnt = 0;
    int connect_cnt = 0;
    fill(visited[0], visited[5], false);
   
    queue<pair<int,int>> q;
   
    bool isStartPoint = true;
    for(int i=0;i<25;i++){
        if(chosen[i] == true) {
           int row = i / 5;
           int column = i % 5;
           
           if(arr[row][column] == 'S') dasom_cnt++;
           
           if(isStartPoint == true) { // BFS 시작점
               visited[row][column] = true;
               q.push({row, column});
               isStartPoint = false;
               connect_cnt = 1;
           }
        }
    }
   
    if(dasom_cnt < 4) return false;  // 다솜파 4명 미만
   
    while(!q.empty()){
        auto [now_row, now_column] = q.front();
        q.pop();
       
        for(int d=0;d<4;d++){
            int next_row = now_row + di[d];
            int next_column = now_column + dj[d];
           
            if(next_column >= 0 && next_column < 5 && next_row >= 0 && next_row < 5) { // 유효 범위 체크
                if(visited[next_row][next_column] == 0) { // 미방문인 경우
                    if(chosen[next_row * 5 + next_column] == true) { // 실제로 선택한 자리인 지
                        visited[next_row][next_column] = true;
                        q.push({next_row, next_column});
                        connect_cnt++;
                    }
                }
            }
        }
    }
   
    if(connect_cnt == 7) return true; // 상하좌우 연결 되었다.
    return false; // 연결이 안 되었다.
}
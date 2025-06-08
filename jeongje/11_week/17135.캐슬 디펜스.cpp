#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int N, M, D;

static int map[16][16];
static int map_copy[16][16];
static bool visited[16][16];
static int answer;
static bool enemyExist, removeEnemyFound;

void BFS(int row, int column);
void backTracking(int start, int count);
int max(int a, int b);


vector<int> archerColumns;
set<pair<int, int>> removeEnemy;

int enemyRow, enemyColumn, castle_row;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main(){
    cin >> N >> M >> D;
   
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
   
   
    // M개의 열에서 궁수 3명의 위치를 백트래킹으로 선정함
    backTracking(0, 0);
    
    
    cout << answer;
}  

void BFS(int row, int column) {
    queue<tuple<int, int, int>> q;
    q.push({row, column, 0});
   
    int minDistance;
    while(!q.empty()) {
        auto [now_row, now_column, dis] = q.front();
        q.pop();
        
        // 같은 거리일 경우 가장 왼쪽에 있는 적을 제거해야 된다의 로직 
        if(map_copy[now_row][now_column] && dis == minDistance) {
            if(now_column < enemyColumn) {
                enemyRow = now_row;
                enemyColumn = now_column;
            }
        }
        
    
        for(int d=0;d<4;d++){
            int next_row = now_row + dr[d];
            int next_column = now_column + dc[d];
           
            if(next_row < castle_row && next_row > -1 && next_column < M && next_column > -1 && !visited[next_row][next_column]) {
                
               if(map_copy[next_row][next_column] && !removeEnemyFound) {  // 적이 있음 && 한 턴에 적은 한명만 소탕 가능 
                   // 유효 사격 거리 내에 있는 경우 
                   if(dis + 1 <= D) {
                       // 적 좌표 기록
                       enemyRow = next_row;
                       enemyColumn = next_column;
                       minDistance = dis + 1;
                       
                       // 한 턴에 적은 한명만 소탕 가능하므로
                       removeEnemyFound = true;
                   }
                   
                   enemyExist = true;
                   
               } else { // 적이 없는 곳 
                   visited[next_row][next_column] = true;
                   
                   q.push({next_row, next_column, dis + 1});
               }
            }
        }
    }
}


void backTracking(int start, int count) {
    if(count == 3) { // 궁수 3명 배치 완료
        
        // 3명의 위치가 정해질때마다 손상된 map을 쓰지 않도록 map을 copy 하고 
        // BFS에서는 map_copy만을 사용함 
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                map_copy[i][j] = map[i][j];
            }
        }
        
        int i = 0;
        int temp = 0;
        castle_row = N; // 초기 성 위치 
        do {
            enemyExist = false;
            removeEnemyFound = false;
            
            // 방문 배열 초기화 
            fill(visited[0], visited[N], 0);
            
            BFS(castle_row, archerColumns[i]);
            
            // map 전체에서 적을 찾지 못한 경우 ( 적이 모두 소탕된 상태  )
            if(!enemyExist) break;
            
            // 유효 사격 거리 안에 있는 적을 찾은 경우 
            if(removeEnemyFound) {
                removeEnemy.insert({enemyRow, enemyColumn});
            }
            
            i++;
            
            
            if(i == 3)  {
                // 궁수는 활을 동시에 쏴야 되기 때문에 
                // 적 제거는 세 명의 궁수가 모두 활을 쏜 다음에 진행한다. 
                for (auto p : removeEnemy) {
                    map_copy[p.first][p.second] = 0;
                    temp++;
                }
                
                i = 0;
                castle_row--; // 성을 한 칸 앞으로 당겨서 적이 다가 오는것과 같은 효과를 줌 
                removeEnemy.clear();
            }
            
        } while(enemyExist);
        
        answer = max(answer, temp);
    }
   
    // 궁수 위치 정하는 과정 
    for(int i = start; i < M; i++) {
        archerColumns.push_back(i);
        backTracking(i + 1, count + 1);
        archerColumns.pop_back();
    }
}


int max(int a, int b) {
    if(a < b) return b;
    else return a;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int map[50][50];
static bool visited[50][50];

void BFS(int x,int y);

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};

int map_x, map_y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int cnt = 0;
        int spot_num;
        
        fill(&map[0][0], &map[49][50], 0);
        fill(&visited[0][0], &visited[49][50], false);
        
        cin >> map_x >> map_y >> spot_num;
        for(int i=0;i<spot_num;i++){
            int spot_x, spot_y;
            cin >> spot_x >> spot_y;
            map[spot_x][spot_y] = 1;
        }
        
        for(int i=0;i<map_x;i++){
            for(int j=0;j<map_y;j++){
                if(!visited[i][j] && map[i][j]){
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        
        cout << cnt << "\n";
    }
}

void BFS(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int next_x = node.first + mx[i];
            int next_y = node.second + my[i];
            if(next_x > -1 && next_x < map_x && next_y > -1 && next_y < map_y) {
                if(!visited[next_x][next_y] && map[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
}
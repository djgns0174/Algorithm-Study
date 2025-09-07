#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans = -1;
int arr[500][500];
static bool visited[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0 , 0, -1 , 1};

void dfs(int r, int c, int count, int sum);
void check_extra_shape(int r, int c);

int main() {
    cin >> N >> M;
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            check_extra_shape(i, j);
            visited[i][j] = false;
        }
    }
    
    cout << ans;
}

void dfs(int r, int c, int count, int sum) {
    if(count == 4) {
        ans = max(ans, sum);
        return;
    }
    
    for(int d=0;d<4;d++){
        int next_r = r + dr[d];
        int next_c = c + dc[d];
        
        if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
        if(visited[next_r][next_c]) continue;
        
        visited[next_r][next_c] = true;
        dfs(next_r, next_c, count + 1, sum + arr[next_r][next_c]);
        visited[next_r][next_c] = false;
    }
}

void check_extra_shape(int r, int c) {
    int shape[4][4][2] = {
        {{0,0}, {-1, 0}, {1, 0}, {0, 1}}, // ㅏ
        {{0, 0}, {0, -1}, {-1, 0}, {1, 0}}, // ㅓ
        {{0, 0}, {0, 1}, {0, -1}, {-1 ,0}}, // ㅗ 
        {{0,0}, {1, 0}, {0, -1}, {0, 1}}, // ㅜ
    };
    
    for(int i=0;i<4;i++){
        int sum = 0;
        bool ok = true;
        for(int j=0;j<4;j++) {
            int nr = r + shape[i][j][0];
            int nc = c + shape[i][j][1];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) {
                ok = false;
                break;
            }
            
            sum += arr[nr][nc];
        }
        if(ok) ans = max(ans, sum);
    }
}
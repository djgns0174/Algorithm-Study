#include <iostream>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M, K, result = INT_MAX;

static int map[51][51];
static int map_cp[51][51];
static tuple<int, int, int> k_array[6];
static int order[7];
static bool order_check[7];

void DFS(int count);
void rotation();

int main() {
    cin >> N >> M >> K;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=1;i<=K;i++){
        int r,c,s;
        cin >> r >> c >> s;
        k_array[i] = {r, c, s};
    }
    
    // 1~K번의 순서를 정하는 DFS
    DFS(1);
    
    cout << result;
}

void rotation()
{
    for (int k = 1; k <= K; k++) {
        auto [r, c, s] = k_array[order[k]];
        
        for (int layer = 1; layer <= s; layer++) {
            int top = r - layer;
            int left = c - layer;
            int bottom = r + layer;
            int right = c + layer;

            // 테두리 값 보존
            int prev = map_cp[top][left];
            
            // 왼쪽 -> 위
            for (int i = top; i < bottom; i++)
                map_cp[i][left] = map_cp[i + 1][left];
            // 아래 -> 왼쪽
            for (int i = left; i < right; i++)
                map_cp[bottom][i] = map_cp[bottom][i + 1];
            // 오른쪽 -> 아래
            for (int i = bottom; i > top; i--)
                map_cp[i][right] = map_cp[i - 1][right];
            // 위 -> 오른쪽
            for (int i = right; i > left + 1; i--)
                map_cp[top][i] = map_cp[top][i - 1];
            
            // 마지막에 저장했던 값 넣기
            map_cp[top][left + 1] = prev;
        }
    }
    
    int temp_min = INT_MAX;
    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=1;j <=M;j++){
            sum += map_cp[i][j];
        }
        temp_min = min(temp_min, sum);
    }
    
    result = min(result, temp_min);
}


void DFS(int count) 
{
    if(count == K+1) // 순서 정하기 완료 
    {
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                map_cp[i][j] = map[i][j];
            }
        }
        
        rotation();
        return;
    }
    
    for(int i=1;i<=K;i++){
        if(order_check[i] == false)
        {
            order[i] = count;
            order_check[i] = true;
            DFS(count + 1);
            order_check[i] = false;        
        }
    }
}
#include <iostream>

using namespace std;

enum Direction 
{
    HORIZONTAL, // 가로
    VERTICAL,   // 세로
    DIAGONAL,   // 대각선 
};

int N;
static int home[17][17];
static int count;

void DFS(int row, int column, int dic);

int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1};

int main(){
    cin >> N;
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> home[i][j];
        }
    }
    
    DFS(1, 2, HORIZONTAL);
    
    cout << count;
}


void DFS(int row, int column, int dic) {
    if(row == N && column == N) // 목적지 달성 
    {
        count++;
        return;
    }
    
    for(int i=0;i<3;i++)
    {
        // 가로 → 세로 || 세로 → 가로   이동은 불가능 
        if((dic == HORIZONTAL && i == VERTICAL) || (dic == VERTICAL && i == HORIZONTAL))
        {
            continue;
        }
        
        int next_row = row + dr[i];
        int next_column = column + dc[i];
        
        // 벽이거나 집 범위를 넘어가는 경우 
        if((home[next_row][next_column] == 1) || (next_row < 1) || (next_row > N) || (next_column < 1) || (next_column > N))
        {
            continue;
        }
        
        // 대각선 이동에서 나머지 두 공간 중 벽이 있는 경우 
        if((i == DIAGONAL) && ((home[row+1][column] == 1) || (home[row][column+1] == 1)))
        {
            continue;
        }
        
        DFS(next_row, next_column, i);
        
    }
}
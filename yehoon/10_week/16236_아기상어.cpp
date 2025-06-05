#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"

using namespace std;

/*
    [구현]
    1. BFS로 물고기 먹는다.
        1. 자신보다 물고기 크면 return 
        2. 작으면
            1. eat++, 상어 크기 변할수 있는지 체크, answer += depth, depth초기화, visited 초기화, 4방향 이동
        3. 같거나 물고기가 없으면
            1. depth+1, visited 설정, 4방향 이동
    2. 더 이상 갈곳이 없으면 answer 출력

    [시간 복잡도] 
    최악의 경우 모든 방향을 탐색하고 가장 큰 거리를 이동하면서 물고기를 계속 먹으러 다닐때
    = 40 * 400 * 4(방향) = 시간통과 
*/

int n;
int answer = 0;
int eat = 0;
int sharkSize = 2;
queue<pair<int,int>> q;
vector<vector<bool>> visited;
vector<vector<int>> arr;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int depth)
{
    // 현재 위치값
    int i = q.front().first;
    int j = q.front().second;

    // 모든 경우 탐색했는지 확인
    bool end = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j]) end = false;
        }
    }
    if(end)
    {
        cout << answer << endl;
        exit(0);
    }

    // 범위를 벗어나면
    if(i<0 || j<0 || i>=n || j>=n) return;

    // 물고기가 크면
    if(arr[i][j] > sharkSize) return;

    // 물고기가 같거나 없으면
    else if(arr[i][j] == sharkSize || arr[i][j] == 0)
    {
        visited[i][j] = true;
        for(int k=0; k<4; k++)
        {
            int nextI = i + dx[k];
            int nextJ = j + dy[k];

            pair<int,int> p = {nextI, nextJ};
            q.push(p);

            bfs(depth+1);
        }
        visited[i][j] = false;
    }

    // 물고기가 작으면
    else 
    {
        eat++;
        if(eat == sharkSize)
        {
            sharkSize++;
            eat = 0;
        }
        answer += depth;
        depth = 0;

        // visited 초기화
        visited = vector<vector<bool>>(n, vector<bool>(n, false));

        // visited 설정 후 이동
        visited[i][j] = true;
        for(int k=0; k<4; k++)
        {
            int nextI = i + dx[k];
            int nextJ = j + dy[k];

            pair<int,int> p = {nextI, nextJ};
            q.push(p);

            bfs(depth+1);
        }
        visited[i][j] = false;
    }
}

int main(void)
{
    cin >> n;
    
    arr = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    pair<int,int> p;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 9) p = {i,j};
        }
    }

    visited[p.first][p.second] = true;
    bfs(1);
    
    return 0;
}
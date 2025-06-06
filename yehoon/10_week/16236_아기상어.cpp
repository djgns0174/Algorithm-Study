#include<iostream>
#include<vector>
#include<queue>
#include <functional>  
#define endl "\n"

using namespace std;

/*
    [구현 -> 틀림]
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

    [틀린이유]
    BFS를 BFS로 사용하지 않았다. 
    즉 BFS 수행 과정에서 아기상어가 물고기를 먹을 수 있으면 바로 먹게 했다. 
    이 결과 문제 조건인 
        “ 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라	면, 가장 왼쪽에 있는 물고기를 먹는다. “ 
    것을 충족하지 못하게 된다. 
    *중요* dx, dy 를 위쪽과 왼쪽 우선으로 설정했더라도 큐에 먼저 들어온 순서에 따라 처리가 되어서 우선순위가 완전히 보장되지 않는다. 
    그러므로 먹을 수 있는 물고기를 모두 탐색한 뒤 조건에 맞는 물고기를 먹고 해당 자리로 이동해야된다. 

    [구현2 -> 정답]
    1. 반복문을 계속 수행하여 시작 위치에서 먹을 수 있는 물고기를 탐색한다.
    2. 먹을 수 있는 물고기들을 거리 위치 순으로 우선순위 큐에 삽입한다. 
    3. 큐.front()에서 물고기를 먹고 해당 물고기의 위치로 이동한다.
        1. Eat ++, 상어 크기 변할수 있는지 체크, answer += depth(거리), depth초기화, visited 초기화, 큐 초기화,다시 1번 반복문 반복
    4. 먹을 수 없는 물고기 밖에 없으면 반복문 종료 후 answer 출력
*/

int n;
int answer = 0;
int eat = 0;
int sharkSize = 2;
queue<pair<int,pair<int,int>>> q;
vector<vector<bool>> visited;
vector<vector<int>> arr;

priority_queue<
    pair<int, pair<int, int>>,  // {거리, {행, 열}}
    vector<pair<int, pair<int, int>>>,
    function<bool(pair<int, pair<int, int>>, pair<int, pair<int, int>>)>
> candidate_fish(
    [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
        if (a.first != b.first) return a.first > b.first;  // 거리 오름차순
        if (a.second.first != b.second.first) return a.second.first > b.second.first;  // 위쪽 우선
        return a.second.second > b.second.second;  // 왼쪽 우선
    }
);

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

void bfs()
{
    while(1)
    {
        while(!q.empty())
        {
            // 현재 깊이
            int depth = q.front().first;

            // 현재 위치값
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            // 물고기가 작으면
            if(arr[i][j] < sharkSize && arr[i][j] > 0)
            {   
                pair<int, pair<int,int>> p = {depth, {i, j}};
                candidate_fish.push(p);
            }

            // 물고기가 같거나 없으면
            else if(arr[i][j] == sharkSize || arr[i][j] == 0 || arr[i][j] == 9)
            {
                for(int k=0; k<4; k++)
                {
                    int nextI = i + dy[k];
                    int nextJ = j + dx[k];

                    if(nextI<0 || nextJ<0 || nextI>=n || nextJ>=n) continue;
                    if(visited[nextI][nextJ]) continue;

                    pair<int, pair<int,int>> p = {depth+1, {nextI, nextJ}};
                    visited[nextI][nextJ] = true;

                    q.push(p);
                }
            }
            // 물고기가 크면
            else continue;
        }

        // 먹을 수 있는 물고기가 없다면 종료
        if(candidate_fish.empty()) return;

        // 먹을 수 있는 물고기가 있다면 먹기
        pair<int, pair<int,int>> p = candidate_fish.top(); candidate_fish.pop();

        int i = p.second.first; int j = p.second.second;
        int dist = p.first;

        arr[i][j] = 0;

        if(++eat == sharkSize)
        {
            sharkSize++;
            eat = 0;
        }

        answer += dist;
        
        //visited 초기화, 우선순위 큐 초기화
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        while(!candidate_fish.empty()) candidate_fish.pop();

        visited[i][j] = true;

        pair<int, pair<int,int>> init = {0, {i, j}};
        q.push(init);
    }
}

int main(void)
{
    cin >> n;
    
    arr = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    pair<int,pair<int,int>> p;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];

            // 상어 시작 위치 저장
            if(arr[i][j] == 9) p = {0,{i,j}};
        }
    }

    // 상어 시작 위치 방문처리
    visited[p.second.first][p.second.second] = true;
    arr[p.second.first][p.second.second] = 0;

    q.push(p);

    bfs();

    cout << answer << endl;
    
    return 0;
}
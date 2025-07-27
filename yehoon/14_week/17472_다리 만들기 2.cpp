#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#define endl "\n"

using namespace std;

/*
    다리 만들기 2 - 17472

    [구현 및 BFS]
    다리를 설치할 수 있는 경우를 전부 탐색한다. (조합)
    다리를 조합해서 모든 섬이 연결되는지 확인한다.
    모든 섬이 연결되었으면 우선순위 큐에 삽입한다. 

    [모듈 종류]
    1. 다리의 모든 경우를 탐색하는 모듈
    2. 다리를 설치할 수 있는지 확인하는 모듈
    3. 설치할 수 있는 다리를 조합하는 모듈 (섬의 개수 - 1 부터)
    4. 모든 섬이 연결되는지 확인하는 모듈

    [시간복잡도]
    최악의 경우 N : 10 , M : 10 , 섬의 개수 : 6 이라고 할때 
    6C2(다리의 모든 경우) * 10(다리 설치 확인) + (15C5 + … + 15C15)(설치할 다리 조합) * 100(모든 섬 연결 확인) = 3,082,700
    으로 통과
*/

int N, M;
int answer = INT_MAX;
vector<vector<int>> arr; // 입력 배열

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};

// 섬 구조체
struct Island
{
    vector<pair<int,int>> positions;    // 섬의 위치를 나타내는 배열
    int index;                          // 섬의 인덱스
};
vector<Island> islands;

// 다리 구조체
struct Bridge
{
    vector<pair<int,int>> connects;     // 어떤 섬들을 연결했는지
    int length;                         // 다리의 길이
    vector<pair<int,int>> path;         // 다리의 경로를 나타내는 배열
};
vector<Bridge> bridges;

// 설치된 다리를 조합해서 모든 섬이 연결될 수 있는지
void bridge_combination(int start, int n, int r, int depth, vector<int>bridge_comb, vector<bool>visited)
{
    if(depth == r) // 모든 섬이 연결되는지 확인
    {
        vector<Bridge> selected_bridges;
        for(int bridge_idx : bridge_comb) selected_bridges.push_back(bridges[bridge_idx]);

        vector<bool> island_visited(islands.size(), false);
        queue<int>q;

        int start = selected_bridges[0].connects[0].first;
        q.push(start); island_visited[start] = true;

        int cost = 0;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();

            for(Bridge bridge : selected_bridges)
            {
                for(pair<int,int> p : bridge.connects)
                {
                    if(p.first == cur)
                    {
                        int next = p.second;
                        if(island_visited[next] == true) continue;
                        q.push(next); island_visited[next] = true;

                        cost += bridge.length;
                    }
                }
            }
        }

        // 연결 그래프인지
        bool connect = true;
        for(bool b : island_visited)
        {
            if(b == false) connect = false;
        }

        // 연결 그래프라면 다리 길이 저장
        if(connect)
        {
            answer = min(answer, cost);
        }

        return;
    }

    for(int i=start; i<n; i++)
    {
        if(visited[i] == false)
        {
            bridge_comb.push_back(i); visited[i] = true;
            bridge_combination(i+1, n, r, depth+1, bridge_comb, visited);
            bridge_comb.pop_back(); visited[i] = false;
        }
    }
}

// 섬과 섬을 연결하는 경우와 다리 설치할 수 있는지
void island_combination(int start, int n, int r, int depth, vector<int>island_comb, vector<bool>visited)
{
    // 섬이 연결될 수 있는지
    if(depth == r)
    {   
        // 더 작은 섬 구하기
        int island_idx1 = island_comb[0];
        int island_idx2 = island_comb[1];

        Island island1 = islands[island_idx1];
        Island island2 = islands[island_idx2];

        Island small_island; Island big_island;
        if(island1.positions.size() < island2.positions.size()) 
        {
            small_island = island1;
            big_island = island2;
        }
        else
        {
            small_island = island2;
            big_island = island1;
        }

        // 다리 설치 되는지 확인 및 설치
        Bridge min_bridge;
        min_bridge.length = INT_MAX;
        for(pair<int,int> p : small_island.positions)
        {
            // 상하 좌우로 탐색해서 다리 설치 되는지
            for(int i=0; i<4; i++)
            {
                int cur_i = p.first; int cur_j = p.second;
                int cnt = 0;

                vector<pair<int,int>> path;

                for(int l=0; l<10; l++)
                {
                    cnt++;
                    cur_i += di[i]; cur_j += dj[i];
                    if(cur_i < 0 || cur_j < 0 || cur_i >= N || cur_j >= M) break;

                    pair<int,int> cur = {cur_i, cur_j};

                     // 연결해야될 섬이 아니면(중간에 섬이 막고있다면)
                    if(arr[cur_i][cur_j] == 1 && find(big_island.positions.begin(), big_island.positions.end(), cur) == big_island.positions.end())
                        break;

                    if(arr[cur_i][cur_j] == 0) path.push_back({cur_i, cur_j}); // 다리의 경로 저장

                    // 연결해야될 섬과 만나면
                    if(arr[cur_i][cur_j] == 1 && find(big_island.positions.begin(), big_island.positions.end(), cur) != big_island.positions.end())
                    {
                        Bridge bridge;
                        bridge.length = cnt - 1;

                        if(bridge.length > 1)
                        {
                            bridge.connects.push_back({small_island.index, big_island.index});
                            bridge.connects.push_back({big_island.index, small_island.index});
                            bridge.path = path;
                            
                            if(bridge.length < min_bridge.length) min_bridge = bridge;
                        }

                        break;  // 섬과 만나면 탈출
                    }
                }
            }
        }
        if(min_bridge.length != INT_MAX) bridges.push_back(min_bridge);
        
        return;
    }

    for(int i=start; i<n; i++)
    {
        if(visited[i] == false)
        {
            island_comb.push_back(i); visited[i] = true;
            island_combination(i, n, r, depth+1, island_comb, visited);
            island_comb.pop_back(); visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M;

    arr = vector<vector<int>>(N, vector<int>(M));
    
    // 입력받기
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
    
    // 섬 위치 인식
    int island_cnt = 0;
    queue<pair<int,int>>q; 
    vector<vector<bool>> visited(N, vector<bool>(M, 0));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(visited[i][j]) continue;

            if(arr[i][j] == 1)
            {
                Island island;
                island.index = island_cnt++;
                island.positions.push_back({i,j});
                
                q.push({i,j}); visited[i][j] = true;
                while(!q.empty())
                {
                    pair<int,int>cur = q.front(); q.pop();
                    int cur_i = cur.first; int cur_j = cur.second;

                    for(int k=0; k<4; k++)
                    {
                        int next_i = cur_i + di[k]; 
                        int next_j = cur_j + dj[k];

                        if(next_i < 0 || next_j < 0 || next_i >= N || next_j >= M) continue;
                        if(visited[next_i][next_j]) continue;

                        if(arr[next_i][next_j] == 1)
                        {
                            q.push({next_i, next_j}); visited[next_i][next_j] = true;
                            island.positions.push_back({next_i, next_j});
                        }
                    }
                }
                islands.push_back(island);
            }
        }
    }

    // 섬을 조합해서 다리를 설치할 수 있는지 확인
    vector<int> island_comb; vector<bool> island_visited = vector<bool>(island_cnt, 0);
    island_combination(0, island_cnt, 2, 0, island_comb, island_visited);

    // 설치된 다리 조합
    int bridge_cnt = bridges.size();
    vector<int> bridge_comb; vector<bool> bridge_visited = vector<bool>(bridge_cnt, 0);
    for(int i=island_cnt-1; i<=bridge_cnt; i++)
    {
        bridge_combination(0, bridge_cnt, i, 0, bridge_comb, bridge_visited);
    }

    if(answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}
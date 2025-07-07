#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define endl "\n"
using namespace std;

/*
    게리맨더링 - 17471

    1. 선거구를 먼저 나눈다. (DFS 조합)
    2. 각 구역이 연결되어 있는지 확인한다. (BFS)
        1. 연결되어 있지 않으면 다시 선거구역을 나눈다. (DFS 계속 적용)
        2. 연결되어 있으면 인구수의 차이를 구한다. (기저조건)

    [시간복잡도]
    최악의 경우 N = 10
    구역 나누기(10C1 + 10C2 + … + 10C5) * 연결확인(10 * 10 / 2) * 인구수 구하기(10+10)
    = 약 100만 으로 시간통과

    [틀린 이유]
    연결 확인할때 BFS로 탐색을 하는데 구역에 속한것만 탐색을 수행해야된다.
    큐에 삽입할 때 구역에 속하지 않은 것은 X
*/

int n;
vector<vector<int>> graph;
vector<int> population;
priority_queue<int, vector<int>, greater<int>> pq;

// 인구수 구하기
int getPopulation(vector<int>zone)
{
    int return_value = 0;
    for(int zone_value : zone)
    {
        return_value += population[zone_value]; 
    }

    return return_value;
}

// 연결되어 있는지 확인하기
bool isConnected(vector<int>zone)
{
    vector<bool>visited(n+1, 0);
    queue<int>q;

    q.push(zone[0]);
    visited[zone[0]] = true;

    // BFS로 연결 확인
    while(!q.empty())
    {
        int cur = q.front(); q.pop();

        for(int graph_value : graph[cur])
        {
            if(visited[graph_value]) continue;
            if(find(zone.begin(), zone.end(), graph_value) == zone.end()) continue; // 틀린부분 : BFS로 찾되 구역에 속하지 않으면 탐색 X
            q.push(graph_value);
            visited[graph_value] = true;
        }
    }

    for(int zone_value : zone) if(visited[zone_value] == 0) return false;

    return true;
}

// 구역 나누기
vector<bool>used(n+1, 0);
void divide_zone(int start, int r, int depth, vector<int>zone)
{
    if(depth == r)
    {
        vector<int>zone2;
        for(int i=1; i<=n; i++)
        {
            if(find(zone.begin(), zone.end(), i) == zone.end())
                zone2.push_back(i);
        }

        if(isConnected(zone) && isConnected(zone2))
        {
            int diff = abs(getPopulation(zone) - getPopulation(zone2));
            pq.push(diff);
        }
    }

    else
    {
        for(int i=start; i<=n; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                zone.push_back(i);
                divide_zone(i+1, r, depth+1, zone);
                zone.pop_back();
                used[i] = false;
            }
        }
    }
}

int main(void)
{
    cin >> n;

    population = vector<int>(n+1);
    for(int i=1; i<=n; i++) cin >> population[i];

    graph = vector<vector<int>>(n+1);
    for(int i=1; i<=n; i++)
    {
        int conn_num; cin >> conn_num;
        graph[i] = vector<int>(conn_num);
        
        for(int j=0; j<conn_num; j++) cin >> graph[i][j];
    }

    for(int i=1; i<=n/2; i++)
    {
        vector<int>zone;
        divide_zone(1, i, 0, zone);
    }

    if(pq.empty()) cout << -1 << endl;
    else cout << pq.top() << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(11);
vector<int> population(11);
static vector<bool> check(11);

void DFS(int x, int cnt);
bool is_connect(vector<int>& group);

int min_diff = INT_MAX;
int N;

int main()
{
    cin >> N;
    
    for(int i=1;i<=N;i++)
        cin >> population[i];
        
    for(int i=1;i<=N;i++)
    {
        int cnt;
        cin >> cnt;
        
        for(int j=1;j<=cnt;j++)
        {
            int v;
            cin >> v;
            graph[i].push_back(v);
        }
    }
    
    DFS(1, 0);
    
    if(min_diff == INT_MAX) cout << -1;
    else cout << min_diff;
}


void DFS(int x, int cnt)
{
    if(cnt >= 1)
    {
        vector<int> groupA, groupB;
        int sumA = 0, sumB = 0;
        for(int i=1;i<=N;i++)
        {
            if(check[i] == 0)
            {
                groupA.push_back(i);
                sumA += population[i];
            }
            else
            {
                groupB.push_back(i);
                sumB += population[i];
            }
        }
        
        
        if((is_connect(groupA)) && (is_connect(groupB)))
        {
            min_diff = min(min_diff, abs(sumA - sumB));
        }
    }
    
    if(cnt == N-1) return;
    
    for(int i=x;i<=N;i++)
    {
        if(check[i] == true) continue;
        
        check[i] = true;
        DFS(i, cnt + 1);
        check[i] = false;
    }
    
}

bool is_connect(vector<int>& group)
{
    vector<bool> visited(N+1, false);
    
    queue<int> q;
    q.push(group[0]);
    
    visited[group[0]] = true;
    
    int count = 1;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(int next: graph[now])
        {
            if(!visited[next] && find(group.begin(), group.end(), next) != group.end())
            {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    
    return count == group.size();
}
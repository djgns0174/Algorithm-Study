#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    소문난 칠공주 - 1941

    [백트래킹]
    1. for문으로 모든 경우를 시작 위치로 둔다.
    2. 해당 위치에서 갈 수 있는 경우의 수(위, 아래, 옆)를 모두 탐색(함수 호출)
        1. 행렬의 바깥이면 return
        2. 안쪽이면 계속 탐색
        3. 임도연 파가 4명이 감지되면 return
    3. 7명을 결성하면 answer 증가
    4. 1번 for문이 끝나면 answer 출력

    -> 해당 방법을 사용하면 모든 경우의 수를 따질 수 없다.(T자형)

    [조합 + BFS]
    1. 25개의 좌표값에서 7개를 조합한다. 
        1. 임도연파가 4명이 감지되면 return
    2. 해당 7개의 좌표값이 소문난 7공주를 결성할 수 있는지 확인한다.
        1. 7개의 좌표중 하나의 좌표값을 큐에 넣는다. (시작)
        2. 큐에서 좌표값을 빼서 방문 처리한뒤 인접한 좌표값을 모두 큐에 넣는다. 
        3. 다시 큐에서 좌표값을 빼서 인접한 좌표값을 모두 큐에 넣기를 반복한다.
        4. 큐에 넣을 때 마다 카운트를 증가시키고 해당 카운트값이 7이면 answer증가
    3. answer를 출력한다.

    [조합 + BFS 시간 복잡도] 
    25C7(25개의 좌표값에서 7개 조합 경우의 수) * 7(소문난 칠공주 조건 확인)
    = 약300만으로 시간 통과

    **중요**
    [조합 + BFS 틀린 이유]
    해당 7개의 좌표값이 소문난 7공주인지 확인하는 과정에서 BFS를 사용하였다.
    1. 방문여부를 안따졌더니 인접한 좌표끼리 계속 왔다갔다 하는 무한루프가 발생하였다.
    2. BFS 구현 시 큐에 넣을 때가 아닌 큐에서 뺄 때 방문처리를 해주어서 동일한 좌표값이 중복해서 들어가는 문제가 발생하였다. 큐에 넣을때 방문처리를 해주어야지 다음 좌표에서 동일한 좌표값을 넣게 되지 않는다.

    -> BFS구현시에 방문여부를 꼭 따지자! 큐에 넣을때 방문여부 처리를 해주자!
*/

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int answer = 0;

vector<char>arr;

void combination(int start, int depth, pair<int, int>p, vector<pair<int,int>>comb)
{
    if(depth == 7 && p.first >= 4)
    {
        vector<pair<int,int>>v;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(5, vector<bool>(5, false));

        q.push(comb[0]);
        visited[comb[0].first][comb[0].second] = true;
        v.push_back(comb[0]);

        while(!q.empty())
        {
            pair<int,int>cur = q.front(); q.pop();
            
            for(int i=0; i<4; i++)
            {
                pair<int,int>next = {cur.first+dx[i], cur.second+dy[i]};

                if(next.first<0 || next.first >=5 || next.second<0 || next.second>=5) continue;
                if(visited[next.first][next.second]) continue;

                auto it = find(comb.begin(), comb.end(), next);
                if(it != comb.end())
                {
                    q.push(next);
                    visited[next.first][next.second] = true; 
                    v.push_back(next);
                }
            }
        }

        if(v.size() == 7) {
            answer++;
        }
    }

    else if(p.second >= 4) return;

    else 
    {
        for(int k=start; k<arr.size(); k++)
        {
            if(arr[k] == 'S') p.first++;
            else p.second++;

            int i = k/5; int j = k%5;
            comb.push_back({i,j});

            //test
            // cout << "(" << i << ":" << j << ")" <<endl;

            combination(k+1, depth+1, p, comb);
            
            if(arr[k] == 'S') p.first--;
            else p.second--;

            comb.pop_back();
        }
    }
}

int main(void)
{

    for(int i=0; i<5; i++)
    {
        string input; cin >> input;
        for(int j=0; j<5; j++) 
        {
            arr.push_back(input[j]);
        }
    }

    pair<int, int>p; vector<pair<int,int>>comb;
    combination(0, 0, p, comb);

    cout << answer << endl;
    
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

#define endl "\n"

using namespace std; 

/*
    파이프 옮기기 1 - 17070

    [BFS] 

    1. 현재 위치에서 갈 수 있는 경우를 모두 큐에 삽입한다. 
        1. 큐에 넣는 자료 형태 : 파이프의 방향, {위치y, 위치x}
        2. 파이프의 방향에 따라서 갈 수 있는 경우가 바뀜
            1. 가로 -> (0,+1) or (+1, +1)
            2. 세로 -> (+1, 0) or (+1, +1)
            3. 대각선 -> (0,+1) or (+1, 0) or (+1, +1)
            4. 단, 파이프를 이동할때 벽을 고려한다. 
        3. 파이프 이동할때 조건 (다음 위치)
            1. 벽이 다음 위치에 있으면 안된다.
                1. 가로 -> (0,+1)
                2. 세로 -> (+1, 0)
                3. 대각선 -> (0,+1) or (+1, 0) or (+1, +1)
        4. 해당 위치의 방법의 수를 +1 한다. 

    가로 : 0 
    세로 : 1
    대각선 : 2
*/

vector<vector<int>> home;
vector<vector<int>> answer;
queue<pair<int, pair<int,int>>> q;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

int main(void)
{
    int n; cin >> n;

    home = vector<vector<int>>(n, vector<int>(n));
    answer = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            cin >> home[i][j];

    // 처음 파이프 위치 세팅
    answer[0][0] = 1;
    pair<int, int>p = {0, 1};
    q.push({0, p});

    // BFS
    while(!q.empty())
    {
        int x = q.front().second.second;
        int y = q.front().second.first;
        int direction = q.front().first;
        q.pop();

        answer[y][x] ++; // 방문 처리

        // 파이프 방향이 가로라면 
        if(direction == 0)
        {
            for(int i=1; i<=2; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= n || ny >= n) continue;

                pair<int, int> p = {ny, nx};

                // 가로 방향으로 이동하고 벽이 존재하지 않을때
                if(i==1 && !home[ny][nx])
                    q.push({0, p});

                // 대각선 방향으로 이동할 때 벽이 존재하면
                else
                {
                    if(i==2 && !home[ny][nx] &&!home[y+1][x] && !home[y][x+1])
                        q.push({2, p});
                }
            }
        }

        // 파이프 방향이 세로라면
        else if(direction == 1)
        {
            for(int i=0; i<=2; i++)
            {   
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= n || ny >= n) continue;

                pair<int, int> p = {ny, nx};

                // 세로 방향으로 이동하고 벽이 존재하지 않을때
                if(i==0 && !home[ny][nx])
                    q.push({1, p});

                // 대각선 방향으로 이동할 때 벽이 존재하면
                else
                {
                    if(i==2 && !home[ny][nx] &&!home[y+1][x] && !home[y][x+1])
                        q.push({2, p});
                }
            }
        }

        // 대각선이라면
        else 
        {
            for(int i=0; i<=2; i++)
            {   
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= n || ny >= n) continue;

                pair<int, int> p = {ny, nx};

                // 가로 방향으로 이동하고 벽이 존재하지 않을때
                if(i==1 && !home[ny][nx])
                    q.push({0, p});

                // 세로 방향으로 이동하고 벽이 존재하지 않을때
                if(i==0 && !home[ny][nx])
                    q.push({1, p});

                // 대각선 방향으로 이동할 때 벽이 존재하면
                else
                {
                    if(i==2 && !home[ny][nx] &&!home[y+1][x] && !home[y][x+1])
                        q.push({2, p});
                }
            }
        }
    }

    //test
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << answer[n-1][n-1] << endl;

    return 0;
}
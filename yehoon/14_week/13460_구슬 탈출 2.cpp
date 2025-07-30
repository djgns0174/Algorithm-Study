#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

#define endl "\n"

using namespace std;
/*
    구슬 탈출 2 - 13460

    [BFS]
    빨간 구슬이 움직일 수 있는 경우(상하좌우)를 큐에 삽입
    큐에서 빼서 빨간, 파란 구슬을 움직인다. 
    - 종료조건 : 두 구슬 다 ‘.’ 또는 ‘O’가 아닐 시

    방향
    오른쪽 : 0
    왼쪽 : 1
    아래 : 2
    위 : 3
*/
int di[4] = {0,0,1,-1};     
int dj[4] = {1,-1,0,0};

int N, M;
int answer = INT_MAX;

struct q_input                  // 큐 삽입 구조체
{
    pair<int,int> cur_red;      // 빨간 구슬의 현재 위치
    pair<int,int> cur_blue;     // 파란 구슬의 현재 위치
    int dir;                    // 빨간 구슬이 가고자 하는 방향
    int depth;                  // BFS 깊이
    vector<vector<char>> q_arr; // 구슬의 현재 위치를 반영한 구슬 판 (디버깅용)
};

struct st_visited               // BFS 방문 여부 구조체
{
    pair<int,int> v_cur_red;    // 빨간 구슬의 현재 위치
    pair<int,int> v_cur_blue;   // 파란 구슬의 현재 위치
    int v_dir;                  // 빨간 구슬이 가고자 하는 방향

    // 연산자 오버로딩
    bool operator==(const st_visited& other) const {
        return v_cur_red == other.v_cur_red &&
               v_cur_blue == other.v_cur_blue &&
               v_dir == other.v_dir;
    }
};
vector<st_visited> visited;

vector<vector<char>> arr;
queue<q_input>q;    // BFS 큐

void q_push_dir(q_input arg_q_input)        // 빨간 구슬이 움직일 수 있는 방향으로 삽입하는 함수
{
    for(int i=0; i<4; i++)
    {
        int next_red_i = arg_q_input.cur_red.first + di[i];
        int next_red_j = arg_q_input.cur_red.second + dj[i];

        q_input input;
        input.cur_blue = arg_q_input.cur_blue;
        input.cur_red = arg_q_input.cur_red;
        input.depth = arg_q_input.depth;
        input.q_arr = arg_q_input.q_arr;

        st_visited target;
        target.v_cur_red = input.cur_red;
        target.v_cur_blue = input.cur_blue;
        target.v_dir = i;

        // 빨간, 파란 구슬의 위치가 동일하고 기울이는 방향도 동일할 시 큐에 삽입하지 않는다. (이미 했던 기울이기는 진행X)
        if (find(visited.begin(), visited.end(), target) == visited.end())
        {
            input.dir = i;
            q.push(input); 
            visited.push_back(target);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    
    arr = vector(N, vector<char>(M));

    // 입력 받기
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];

    q_input init_arg_push_dir;
    pair<int,int> hole;

    // 빨간, 파란 구슬의 위치 찾기
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if (arr[i][j] == 'R')
            {
                init_arg_push_dir.cur_red.first = i;
                init_arg_push_dir.cur_red.second = j;
            }
            
            else if (arr[i][j] == 'B')
            {
                init_arg_push_dir.cur_blue.first = i;
                init_arg_push_dir.cur_blue.second = j;
            }

            else if (arr[i][j] == 'O')
            {
                hole.first = i;
                hole.second = j;
            }

            else continue;
        }
    }

    init_arg_push_dir.depth = 0;
    init_arg_push_dir.q_arr = arr;

    q_push_dir(init_arg_push_dir);

    // RED가 갈 수 있는 방향 출력
    // while(!q.empty())
    // {
    //     q_input input = q.front(); q.pop();
    //     cout << "red :  " << input.cur_red.first << "," << input.cur_red.second << endl;
    //     cout << "dir : " << input.dir << endl;
    //     cout << "blue : " << input.cur_blue.first << "," << input.cur_blue.second << endl << endl;
    // }
    
    while(!q.empty())
    {
        q_input input = q.front(); q.pop();

        int cur_red_i = input.cur_red.first;
        int cur_red_j = input.cur_red.second;

        int cur_blue_i = input.cur_blue.first;
        int cur_blue_j = input.cur_blue.second;
        
        int dir = input.dir;
        int depth = input.depth;
        vector<vector<char>> cp_arr = input.q_arr;

        // cout << "depth " << depth << endl;
        // cout << "dir " << dir << endl;
        // cout << "red : " << cur_red_i << "," << cur_red_j << endl;
        // cout << "blue : " << cur_blue_i << "," << cur_blue_j << endl << endl; //test

        int next_red_i = cur_red_i + di[dir];
        int next_red_j = cur_red_j + dj[dir];

        int next_blue_i = cur_blue_i + di[dir];
        int next_blue_j = cur_blue_j + dj[dir];

        bool is_red_hole = false;
        bool is_blue_hole = false;
        bool is_red_end = false;
        bool is_blue_end = false;

        while 
        (
            cp_arr[next_red_i][next_red_j] == '.' || cp_arr[next_blue_i][next_blue_j] == '.' ||
            cp_arr[next_red_i][next_red_j] == 'O' || cp_arr[next_blue_i][next_blue_j] == 'O'
        )
        {
            if (is_red_end && is_blue_end) break;

            if(!is_red_end)
            {
                if (next_red_i == hole.first && next_red_j == hole.second)
                {
                    is_red_hole = true; is_red_end = true;
                    cp_arr[cur_red_i][cur_red_j] = '.';
                    cur_red_i = next_red_i;
                    cur_red_j = next_red_j;
                }
                else
                {
                    switch (cp_arr[next_red_i][next_red_j])
                    {
                    case '.':
                        cp_arr[cur_red_i][cur_red_j] = '.';
                        cp_arr[next_red_i][next_red_j] = 'R';
                        cur_red_i = next_red_i;
                        cur_red_j = next_red_j;
                        break;
                    
                    case '#':
                        is_red_end = true;
                        break;
                    }
                }
                next_red_i = cur_red_i + di[dir];
                next_red_j = cur_red_j + dj[dir];
            }

            if(!is_blue_end)
            {
                if (next_blue_i == hole.first && next_blue_j == hole.second)
                {
                    is_blue_hole = true; is_blue_end = true;
                    cp_arr[cur_blue_i][cur_blue_j] = '.';
                    cur_blue_i = next_blue_i;
                    cur_blue_j = next_blue_j;
                }
                else 
                {
                    switch (cp_arr[next_blue_i][next_blue_j])
                    {
                    case '.':
                        cp_arr[cur_blue_i][cur_blue_j] = '.';
                        cp_arr[next_blue_i][next_blue_j] = 'B';
                        cur_blue_i = next_blue_i;
                        cur_blue_j = next_blue_j;
                        break;
                    
                    case '#':
                        is_blue_end = true;
                        break;
                    }
                }
                next_blue_i = cur_blue_i + di[dir];
                next_blue_j = cur_blue_j + dj[dir];
            }

            // for (int i=0; i<N; i++) //test
            // {
            //     for (int j=0; j<M; j++)
            //     {
            //         cout << cp_arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

        if(is_red_hole && !is_blue_hole)
        {
            answer = min(answer, depth+1);
        }
        
        if (!is_blue_hole && depth < 9)
        {
            q_input arg_input;
            arg_input.cur_blue = {cur_blue_i, cur_blue_j};
            arg_input.cur_red = {cur_red_i, cur_red_j};
            arg_input.depth = depth + 1;
            arg_input.q_arr = cp_arr;
            
            q_push_dir(arg_input);
        }
    }

    if (answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}
#include<iostream>
#include<queue>
#include<set>
#define endl "\n"
#define archer_number 3

using namespace std;

/*
    1. 조합으로 궁수 배치

    2. 궁수에서 가장 가까운 적 BFS로 탐색
        적이 여러명일 경우 우선순위 큐에 삽입
        제거할 적(위치)을 집합에 삽입(중복 방지)
        궁수 3명을 모두 수행

    3. 집합의 원소(적의 위치)를 꺼내 적 제거
        제거할때마다 answer++ 
        원소(적의 위치)와 같은 위치의 적 0으로 만듦

    4. 턴 끝났으니 반복문으로 적 한칸씩 내림
        2차원 배열 맨 뒤에서부터 y+1을 수행
        N-1행 부터 0행까지 진행
        1이 하나도 없으면 answers 우선순위 큐에 answer 삽입 후 다시 궁수 배치
        1이 하나라도 있으면 다음 턴으로 

    [시간복잡도]
    15C3(궁수배치) * 3(궁수의 수) * 14(BFS) * (15*14)(적을 한칸씩 내림) 
    = 약 400만으로 통과
*/

vector<vector<int>>arr;
vector<int>combination;
priority_queue<int>answers;

int n, m, d; 

int answer = 0;

struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.first != b.first)
            return a.first > b.first; // first가 작은 게 우선
        return a.second.first > b.second.first; // second.first가 작은 게 우선
    }
};

void comb(int start, int depth, int m, int r)
{
    // 궁수 배치가 완료되면
    if(r == depth)
    {
        vector<vector<int>>cpArr = arr;

        answer = 0;

        // 게임 시작
        while(1)
        {
            // 제거할 적 위치
            set<pair<int,int>>enemy;


            // 궁수 한명씩 적을 찾는다. 
            for(int i=0; i<archer_number; i++)
            {
                int archer_x = combination[i];
                int archer_y = n;

                int dx[4] = {0,0,1,-1};
                int dy[4] = {1,-1,0,0};

                // cout << "궁수위치 : " << archer_x << endl; //test

                // 제거할 수 있는 적의 후보(적의 위치가 가장 가까운것, 그다음은 가장 왼쪽)
                priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;

                vector<vector<bool>>visited(n, vector<bool>(m, false));
                queue<pair<int,pair<int,int>>> q;
                pair<int,int>p = {archer_x, archer_y-1};

                visited[archer_y-1][archer_x] = true; 
                q.push({1,p});

                // 제거할 수 있는 적을 찾는다. 
                while(!q.empty())
                {
                    int x = q.front().second.first;
                    int y = q.front().second.second; 
                    int depth = q.front().first; q.pop();

                    // cout << depth << "  " << y  << " " << x << endl;

                    if(cpArr[y][x] == 1 && depth <= d) 
                    {
                        pq.push({depth,{x,y}});
                        // cout << "적위치 : " << depth << " " << x << " " << y << endl;
                    }

                    for(int i=0; i<4; i++)
                    {
                        int nextX = x + dx[i];
                        int nextY = y + dy[i];

                        if(nextX < 0 || nextY < 0 || nextX >= m || nextY >=n) continue;
                        if(visited[nextY][nextX]) continue;

                        pair<int,int> p = {nextX, nextY};
                        visited[nextY][nextX] = true;
                        q.push({depth+1,p});
                    }
                }

                // 가장 가까운 적이 있다면 제거할 적의 위치 삽입
                if(!pq.empty()) enemy.insert({pq.top().second.first, pq.top().second.second});
            }

            //test
            // cout << "궁수 위치 : " ; 
            // for(int v : combination)  cout << v << " ";
            // cout << endl;

            // 적 제거하기
            for(pair<int,int>p: enemy)
            {
                int enemyX = p.first;
                int enemyY = p.second;
                // cout << "적 : " << enemyY << " " << enemyX << endl; //test
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(i==enemyY && j==enemyX)
                        {
                            answer++;
                            cpArr[i][j] = 0;
                        }
                    }
                }
            }
            
            bool end = true;
            vector<vector<int>>temp = cpArr;
            // 턴이 끝났으면 적 이동
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(i == 0) cpArr[i][j] = 0;
                    else 
                    {
                        cpArr[i][j] = temp[i-1][j];
                        if(cpArr[i][j]) end = false;
                    }
                }
            }

            // test
            // cout << endl;
            // for(int i=0; i<n; i++)
            // {
            //     for(int j=0; j<m; j++) cout << cpArr[i][j] << " ";
            //     cout << endl;
            // }
            // cout << endl;

            // 더이상 적이 존재하지 않으면
            if(end) 
            {
                answers.push(answer);
                break;
            }
        }
    }

    // 궁수 배치중 
    else 
    {
        for(int i=start; i<n; i++)
        {
            combination.push_back(i);
            comb(i+1, depth+1, n, r);
            combination.pop_back();
        }
    }
}

int main(void)
{
    cin >> n >> m >> d;

    arr = vector<vector<int>>(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> arr[i][j];

    comb(0, 0, m, 3);

    if(!answers.empty()) cout << answers.top() << endl;
    else cout << 0 << endl;
}
#include<iostream>
#include<set>
#include<vector>
#include<queue>

#define endl "\n"

using namespace std;

/*
    [구현]
    1. 0~256 모든 경우로 땅고르기를 수행한다. 
        1. 땅을 해당 높이로 맞추고 블록을 쌓고 빼는 횟수를 센다.
        2. 현재 가지고 있는 블록은 b와 블록을 빼서 인벤토리에 넣는 횟수를 더한값이다.
        3. 현재 가지고 있는 블록이 쌓는 횟수보다 더 많으면 시간과 높이를 측정한다. 
        4. 시간과 높이를 우선순위 큐에 넣는다. (시간, 높이 오름차순)
    2. 가장 빨리 걸린 땅의 높이가 정답이 된다. 

    [시간복잡도]
    최악의 경우
    N * M * 땅의 높이(땅의 높이가 다 다를때) * log2(256)(우선순위를 넣는 경우)
    = 2500 * 256 * log2(256) = 약 500만으로 통과
*/

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second; // second 내림차순
        return a.first > b.first;       // first 오름차순
    }
};

int main(void)
{
    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> arr[i][j];


    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> answer;

    for(int h=0; h<=256; h++)
    {
        int time = 0;
        
        // 땅고르기
        int up = 0; int down = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // 땅이 현재 높이와 같으면
                if(arr[i][j] == h) continue;

                // 땅이 현재 높이보다 높으면 블록을 쌓는 횟수를 센다.
                else if(arr[i][j] < h)
                {
                    up += h - arr[i][j];
                }
                
                //땅이 현재 높이보다 낮으면 블록을 빼는 횟수를 센다. 
                else 
                {
                    down += arr[i][j] - h;
                }
            }
        }
        
        //현재 블록의 개수
        int block = b + down;
        if(up > block) time = -1;
        else time = 2 * down + up;

        // 우선순위 큐에 시간, 높이 삽입한다.
        answer.push(pair<int,int>{time, h});
    }

    while(!answer.empty())
    {
        if(answer.top().first != -1) 
        {
            cout << answer.top().first << " " <<answer.top().second << endl;
            return 0;
        }
        
        answer.pop();
    }


    return 0;
}
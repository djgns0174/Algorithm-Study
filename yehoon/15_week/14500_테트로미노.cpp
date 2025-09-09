#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

/*
테트로미노 - 14500

[구현] 
각 시작점에서 19가지의 테트로미노를 전부 적용해서 최대가 되는 answer값을 찾는다.
(노가다….)

[시간복잡도]
최대 입력일 경우
종이의 크기 : 250000
테트로미노 회전 대칭 적용한 모든 경우 : 19

250000 * 19 * 3 = 14,250,000으로 통과


*/

vector<vector<int>> dx = vector<vector<int>>(19, vector<int>(3));
vector<vector<int>> dy = vector<vector<int>>(19, vector<int>(3));

void init()
{
    dx[0] = {1,2,2};
    dx[1] = {0,0,1};
    dx[2] = {0,1,2};
    dx[3] = {1,1,1};
    dx[4] = {1,1,1};
    dx[5] = {1,2,2};
    dx[6] = {-1,-1,-1};
    dx[7] = {0,1,2};
    dx[8] = {1,1,2};
    dx[9] = {0,1,0};
    dx[10] = {1,1,2};
    dx[11] = {0,-1,0};
    dx[12] = {0,-1,-1};
    dx[13] = {1,1,2};
    dx[14] = {0,1,1};
    dx[15] = {1,1,2};
    dx[16] = {1,2,3};
    dx[17] = {0,0,0};
    dx[18] = {1,0,1};

    dy[0] = {0,0,-1};
    dy[1] = {1,2,2};
    dy[2] = {-1,-1,-1};
    dy[3] = {0,1,2};
    dy[4] = {0,-1,-2};
    dy[5] = {0,0,1};
    dy[6] = {0,1,2};
    dy[7] = {1,1,1};
    dy[8] = {0,1,0};
    dy[9] = {1,1,2};
    dy[10] = {0,-1,0};
    dy[11] = {1,1,2};
    dy[12] = {1,1,2};
    dy[13] = {0,1,1};
    dy[14] = {1,1,2};
    dy[15] = {0,-1,-1};
    dy[16] = {0,0,0};
    dy[17] = {1,2,3};
    dy[18] = {0,1,1};
}

int main()
{
    vector<vector<int>> arr;

    int N, M;
    cin >> N >> M;

    arr = vector<vector<int>>(N, vector<int>(M));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    init();

    int answer = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            for(int k=0; k<19; k++)
            {
                int sum = arr[i][j];
                bool isComplete = true;

                for(int l=0; l<3; l++)
                {
                    int next_i = i + dy[k][l];
                    int next_j = j + dx[k][l];

                    if(next_i < 0 || next_j < 0 || next_i >= N || next_j >= M)
                    {
                        break;
                        isComplete = false;
                    }
                    
                    sum += arr[next_i][next_j];
                }

                if(isComplete)
                {
                    answer = max(answer, sum);
                }
            }
        }
    }

    cout << answer << endl;
    
    return 0;
}
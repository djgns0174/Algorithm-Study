#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"

using namespace std;

/*
    색종이 붙이기 
    
    [그리디]
    우선순위 큐에 색종이와 위치를 넣어서 가장 큰 색종이부터 처리하는 방식
    1. 1인 부분을 찾는다.
    2. 1인 부분부터 어떤 크기의 색종이를 붙여야되는지 1~5까지 확인한다.
    3. 해당 부분에 색종이 크기와, 위치를 우선순위 큐에 삽입하고 1번을 다시 반복한다. 
    4. 우선순위 큐에서 값을 빼서 empty할때까지 아래를 반복한다.
        1. 우선순위에서 가장 큰 색종이를 붙일 수 있는것부터 뺀다.
        2. 해당 위치부터 색종이를 붙이고 0으로 만든다. Answer ++ 한다. 

    -> 반례 : 6x6 크기의 정사각형이 1로 주어졌을때 5x5 색종이를 먼저 붙이기 때문에 틀림
    0 0 0 0 0 0 0 0 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 1 1 1 1 1 1 0 0
    0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0
*/

vector<vector<int>> arr(10, vector<int>(10));
priority_queue<pair<int, pair<int,int>>> pq;
int answer = 0;

int one_cunfetti_number = 5;
int two_cunfetti_number = 5;
int three_cunfetti_number = 5;
int four_cunfetti_number = 5;
int five_cunfetti_number = 5;

int main(void)
{
    // 입력 받기
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            cin >> arr[i][j];
    }

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(!arr[i][j]) continue;

            pair<int,int> cur_location = {i,j};
            int cunfetti = 1;
            pq.push({cunfetti, cur_location});

            bool twoTrue = true;
            bool threeTrue = true;
            bool fourTrue = true;
            bool fiveTrue = true;

            for(int y=0; y<2; y++)
            {
                for(int x=0; x<2; x++) 
                {
                    if(i+y>=10 || j+x>=10 || !arr[i+y][j+x])
                    {
                        twoTrue = false;
                        break;
                    } 
                }
            }

            for(int y=0; y<3; y++)
            {
                for(int x=0; x<3; x++) 
                {
                    if(i+y>=10 || j+x>=10 || !arr[i+y][j+x])
                    {
                        threeTrue = false;
                        break;
                    } 
                }
            } 

            for(int y=0; y<4; y++)
            {
                for(int x=0; x<4; x++) 
                {
                    if(i+y>=10 || j+x>=10 || !arr[i+y][j+x])
                    {
                        fourTrue = false;
                        break;
                    } 
                }
            } 

            for(int y=0; y<5; y++)
            {
                for(int x=0; x<5; x++) 
                {
                    if(i+y>=10 || j+x>=10 || !arr[i+y][j+x])
                    {
                        fiveTrue = false;
                        break;
                    } 
                }
            } 

                    
            if(twoTrue) pq.push({2,cur_location});
            if(threeTrue) pq.push({3,cur_location});
            if(fourTrue) pq.push({4,cur_location});
            if(fiveTrue) pq.push({5,cur_location});
        }
    }

    while(!pq.empty())
    {
        pair<int,int> cur_location = pq.top().second;
        int cur_i = cur_location.first;
        int cur_j = cur_location.second;

        int cunfetti = pq.top().first;
        pq.pop();

        switch (cunfetti)
        {
            case 1:
            {
                if(arr[cur_i][cur_j] && one_cunfetti_number > 0)
                {
                    arr[cur_i][cur_j] = 0;

                    one_cunfetti_number--;
                    answer++;
                }
                break;
            }
            case 2:
            {
                bool twoTrue = true;
                for(int y=0; y<2; y++)
                {
                    for(int x=0; x<2; x++) 
                    { 
                        // 범위를 벗어나거나 이미 색종이를 붙인 상태라면
                        if(cur_i+y >= 10 || cur_j+x >= 10 || !arr[cur_i+y][cur_j+x]) 
                        {
                            twoTrue = false; 
                            break;
                        }
                    }
                }

                if(twoTrue && two_cunfetti_number > 0)
                {
                    for(int i=0; i<2; i++) 
                    {
                        for(int j=0; j<2; j++) 
                        { 
                            arr[cur_i+i][cur_j+j] = 0; 
                        }
                    }

                    answer++;
                    two_cunfetti_number--;
                    // cout << cunfetti << " " << cur_i << " " << cur_j << endl; //test
                }
                break;
            }
            case 3:
            {
                // 색종이 붙이기 전에 확인
                bool threeTrue = true;
                for(int y=0; y<3; y++)
                {
                    for(int x=0; x<3; x++) 
                    {
                        if(cur_i+y>=10 || cur_j+x >=10) {threeTrue = false; break;}
                        if(!arr[cur_i+y][cur_j+x]) threeTrue = false;
                    }
                }

                if(threeTrue && three_cunfetti_number > 0)
                {
                    for(int i=0; i<3; i++) 
                    {
                        for(int j=0; j<3; j++)
                        {
                            arr[cur_i+i][cur_j+j] = 0;
                        }
                    }

                    answer++;
                    three_cunfetti_number--;
                    // cout << cunfetti << " " << cur_i << " " << cur_j << endl;//test
                }
                break;
            }
            case 4:
            { 
                bool fourTrue = true;
                for(int y=0; y<4; y++)
                {
                    for(int x=0; x<4; x++) 
                    {
                        if(cur_i+y>=10 || cur_j+x >=10) {fourTrue = false; break;}
                        if(!arr[cur_i+y][cur_j+x]) fourTrue = false;
                    }
                } 

                if(fourTrue && four_cunfetti_number > 0)
                {
                    for(int i=0; i<4; i++)
                    {
                        for(int j=0; j<4; j++) 
                        {
                            arr[cur_i+i][cur_j+j] = 0;
                        }
                    }

                    answer++;
                    four_cunfetti_number--;
                    // cout << cunfetti << " " << cur_i << " " << cur_j << endl; //test
                }
                break;
            }
            case 5:
            {
                bool fiveTrue = true;
                for(int y=0; y<5; y++) 
                {
                    for(int x=0; x<5; x++) 
                    {
                        if(cur_i+y>=10 || cur_j+x >=10) {fiveTrue = false; break;}
                        if(!arr[cur_i+y][cur_j+x]) fiveTrue = false;
                    }
                }
                if(fiveTrue && five_cunfetti_number > 0)
                {
                    for(int i=0; i<5; i++) 
                    {
                        for(int j=0; j<5; j++) 
                        {
                            // if(cur_i+i>=10 || cur_j+j >=10){isComplete = false; break; }
                            arr[cur_i+i][cur_j+j] = 0;
                        }
                    }

                    answer++;
                    five_cunfetti_number--;
                    // cout << cunfetti << " " << cur_i << " " << cur_j << endl; //test
                }

                break;
            }
        }
    }

    // 모두 0인지 확인
    bool isComplete = true;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arr[i][j]) isComplete = false;
        }
    }

    if(isComplete) cout << answer << endl;
    else cout << -1 << endl;
    
    return 0;
}
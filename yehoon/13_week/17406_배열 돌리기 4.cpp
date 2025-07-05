#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#define endl "\n"

using namespace std;

/*
    배열 돌리기 4 - 17406

    [DFS]
    Func dfs(깊이, 배열)
    If ( 깊이가 회전연산의 개수와 동일한 경우) 배열의 값을 구하고 우선순위 큐에 삽입
    Else 
        수행할 회전 연산 선택
        회전 연산을 수행한 여부를 체크
        복사된 배열로 회전 연산 수행
        다음 dfs에 전달
        회전 연산 수행한 여부 해제

    [회전 연산 구현]
    맨안쪽 정사각형 부터 맨 바깥쪽 정사각형까지 차례대로 반복한다.
    4가지의 경우의 수로 처리한다.
    1. 정사각형 윗변 : 오른쪽으로 옮김 
    2. 정사각형 오른쪽변 : 밑으로 옮김
    3. 정사각형 밑변 : 왼쪽으로 옮김
    4. 정사각형 왼쪽변 : 위로 옮김


    [시간 복잡도]
    최악의 경우 n, m = 50, k = 6 
    6!(회전 연산 선택) * 2500 (회전 연산 수행) * 6(회전 연산의 개수) = 약 1000만으로 통과
    
*/

int n, m, k;

vector<bool> used;

vector<vector<int>> arr;
vector<vector<int>> rotate_cal_arr;

priority_queue<int, vector<int>, greater<int>> pq;

void func(int depth, vector<vector<int>> cp_arr)
{
    // 회전 연산을 모두 수행하였으면 배열의 값 구하기 
    if(depth == k)
    {
        int arr_value = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int row_sum = 0;
            for(int j=0; j<m; j++)
            {
                row_sum += cp_arr[i][j];
            }
            arr_value = min(arr_value, row_sum);
        }

        pq.push(arr_value);
    }

    else 
    {
        for(int i=0; i<k; i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                vector<int> rotate_cal = rotate_cal_arr[i];

                // 회전 연산 수행
                vector<vector<int>> cp_arr1 = cp_arr;

                for(int l=1; l<=rotate_cal[2]; l++)
                {
                    int start_i = rotate_cal[0] - l - 1;
                    int start_j = rotate_cal[1] - l - 1;

                    int end_i = rotate_cal[0] + l - 1;
                    int end_j = rotate_cal[1] + l - 1;

                    for(int x=start_j; x<end_j; x++) cp_arr1[start_i][x+1] = cp_arr[start_i][x];
                    for(int y=start_i; y<end_i; y++) cp_arr1[y+1][end_j] = cp_arr[y][end_j];
                    for(int x=end_j; x>start_j; x--) cp_arr1[end_i][x-1] = cp_arr[end_i][x];
                    for(int y=end_i; y>start_i; y--) cp_arr1[y-1][start_j] = cp_arr[y][start_j];
                }
                
                func(depth+1, cp_arr1);

                used[i] = 0;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> k;

    arr = vector<vector<int>>(n, vector<int>(m));

    // 배열 입력 받기
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 회전 연산 입력 받기
    rotate_cal_arr = vector<vector<int>>(k, vector<int>(3));
    used = vector<bool>(k, 0);
    for(int i=0; i<k; i++)
    {
        cin >> rotate_cal_arr[i][0] >> rotate_cal_arr[i][1] >> rotate_cal_arr[i][2];
    }
    
    vector<vector<int>> cp_arr = arr;
    
    func(0, cp_arr);

    cout << pq.top() << endl;
    
    return 0;
}
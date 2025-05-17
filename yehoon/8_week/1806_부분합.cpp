#include<iostream>
#include<vector>
#include<climits>
#define endl "\n"

using namespace std;

vector<int>arr(100000, 0);

/*
    부분합 - 1806

    [투포인터]
    1. 1번 포인터값과 2번 포인터값을 0, 1으로 설정한다.
    2. 포인터의 합을 구한다.
        1. 합이 s보다 작으면 2번 포인터의 값을 증가시킨다.
        2. 합이 s보다 크면 1번 포인터의 값을 증가시킨다.
        3. 1번 포인터와 2번 포인터의 값을 증가시킬때 s보다 크면 answer를 min값으로 갱신
    3. 1번 포인터, 2번포인터 중 하나라도 배열의 범위에 벗어나게 되면 종료

    [투포인터 시간 복잡도]
    1번 포인터와 2번 포인터가 교차하면서 증가하면 2n으로 시간 통과하게 된다.
*/

int main(void)
{
    int n, s;
    cin >> n >> s;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int first = 0;
    int second = 1;

    int sum = arr[first];
    int answer = INT_MAX;

    while(first < n && second <= n)
    {
        if(sum < s)
        {
            sum += arr[second++];
        }
        else 
        {
            answer = min(answer , second - first);
            sum -= arr[first++];
        }

        if(answer == 1) break;
    }

    if(answer == INT_MAX) cout << 0 << endl;
    else cout << answer << endl;

    return 0;
}
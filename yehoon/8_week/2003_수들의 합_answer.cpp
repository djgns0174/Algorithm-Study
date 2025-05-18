#include<iostream>
#include<vector>

#define endl "\n"

using namespace std;

/*

    [투포인터]
    1. 1번 포인터와 2번 포인터 0으로 설정
    2. 1번 포인터와 2번 포인터의 값을 더한다.
        1. m보다 작으면 2번 포인터 증가
        2. m보다 크면 1번 포인터 증가
        3. m과 같으면 answer++ 하고 1번포인터 증가

    [투포인터 시간 복잡도]
    n + n 으로 여유롭게 시간 통과함

*/

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int>a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int start = 0; int end = 0;

    int sum = a[0]; int answer = 0;
    while(1)
    {
        if(start >= n || end >= n) break;
        
        if(sum < m) sum += a[++end];
        else if(sum > m) sum -= a[start++];
    
        if(sum == m)
        {
            answer++;
            sum -= a[start++];
        }
    }

    cout << answer << endl;
}
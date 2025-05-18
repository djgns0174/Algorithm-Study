#include<iostream>
#include<vector>

#define endl "\n"

using namespace std;

/*
    [브루트포스]
    1. 완전탐색으로 처음 수열의 시작값을 설정
    2. 다음 연속된 수를 더해서 m을 만들 수 있는지 판단
        1. m보다 작으면 계속 다음수를 더함
        2. m보다 크면 해당 반복문을 나가고 1번 반복문으로 넘어감.

    [브루트포스 시간복잡도]
    최악의 경우 n*(n+1)로 5000만 연산을 수행함.
    0.5초 시간 제한이므로 시간초과가 날 가능성이 존재하지만 해당 문제에서는 통과되었음.
*/

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int answer = 0;
    for(int i=0; i<n; i++)
    {
        int sum = a[i];

        for(int j=i+1; j<n; j++)
        {
            if(sum >= m) break;

            sum += a[j];
        }

        if(sum == m) answer ++;
    }

    cout << answer << endl;

    return 0;
}
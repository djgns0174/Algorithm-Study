#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

/*
    겹치는 건 싫어 - 20922

    [슬라이딩 윈도우]
    1. 1번 포인터, 2번 포인터 모두 0으로 설정
    2. 2번 포인터 값 2차원 배열에 추가한다.
        1. 배열 값이 k를 넘으면 슬라이딩 윈도우로 1번, 2번 포인터 값 증가
        2. 넘지 않으면 2번 포인터 값 증가

    해당 문제는 최장 연속 부분 수열의 길이를 구하는 문제로 
    이전값의 윈도우 크기로 슬라이딩 윈도우 기법을 적용하면 된다.

    [슬라이딩 윈도우 시간복잡도]
    최악의 경우 수열의 길이가 1일때 슬라이딩 윈도우로 n번 탐색한다.

    [틀린 이유]
    숫자 카운트 값을 1번 포인터값을 증가시킬때 감소시켜야되는데 그렇지 못하여서
    중복 카운트가 되었음.
*/

vector<int> a(200000, 0);

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int first = 0;
    a[arr[first]]++;
    int second = 1;
    int answer = 1;

    while(second < n)
    {
        int pushValue = arr[second];
        // cout << pushValue << endl;

        if(k < ++a[pushValue])
        {
            answer = max(answer , second - first);
            while(1)
            {
                int popValue = arr[first];
                if(arr[first] != pushValue) 
                {
                    a[popValue]--; // 틀린 이유 : 숫자 카운트 값을 빼주지 않았음.
                    first++;
                }
                else
                {
                    a[pushValue]--;
                    break;
                }
            }

            first++;
        }

        second++;
    }

    answer = max(answer , second - first);
    cout << answer << endl;

    return 0;
}
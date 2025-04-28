#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    과자 나눠주기

    [이분탐색]
    - 정답에 대한 구간이 존재하며 최대 과자 길이를 찾아야됨.
        - 정답 구간 : 최소 과자 길이 ~ 최대 과자 길이
    - 풀이방법 
        - 정답 구간을 이분탐색으로 최대 과자 길이 탐색
        - 과자 길이를 완전탐색으로 몇명의 조카에게 나누어줄 수 있는지 
            - 조카 수가 부족하다면 end = key - 1 
            - 조카 수가 넘치면 start = key + 1
        - 조카 수가 맞을때 까지 

    [시간 복잡도]
    log(10억)(최대 과자 길이 이분 탐색) * m(조카 수가 맞는지 확인)
    = 100만 * log(10억) 으로 통과
*/

int main(void){

    int n, m;
    cin >> m >> n;

    vector<int>l(n);
    for(int i=0; i<n; i++)
        cin >> l[i];

    sort(l.begin(), l.end());
    
    int start = 1;
    int end = l[n-1];

    int answer = 0;
    while(start <= end)
    {
        int give = 0;
        int key = (start + end) / 2;

        for(int i=0; i<n; i++)
        {
            if(l[i] < key) continue;
            else give += l[i] / key;
        }

        if(m <= give)
        {
            start = key + 1;
            answer = key;
        }
        else if(give < m)
            end = key - 1;
    }

    cout << answer << endl;
    
    return 0;
}
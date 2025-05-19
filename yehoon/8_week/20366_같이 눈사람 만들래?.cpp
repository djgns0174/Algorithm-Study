#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define endl "\n"

using namespace std;

/*
    같이 눈사람 만들래? - 20366

    [투 포인터 + 브루트포스]
    1. 완전탐색으로 먼저 한사람의 눈사람을 만든다.
    2. 눈덩이 두개를 제외한 나머지 눈덩이들 투포인터로 고르고 차이를 구해서 answer에 저장한다.
        1. 양 끝에 포인터를 잡는다.
        2. 먼저 만든 눈사람보다 작으면 1번째 포인터를 증가시킨다.
        3. 크면 2번째 포인터를 감소시킨다. 
        4. 같거나, 두개의 포인터가 만났을 경우 종료한다. 
    
    [시간복잡도]
    n^2/2(완전탐색으로 첫번째 눈사람 만드는 경우) * 2n(투포인터로 두번째 눈사람 만드는 경우)
    = 약 2억으로 시간초과 날 가능성 존재함 -> *다른 알고리즘 모색 필요*
*/

int main(void)
{
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    sort(h.begin(), h.end());

    int answer = INT_MAX;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int snowman1 = h[i] + h[j];

            int first = 0;
            int second = n - 1;
            while(first < second)
            {
                if(first == i || first == j) {first++; continue;}
                if(second == i || second == j) {second--; continue;}

                int snowman2 = h[first] + h[second];

                answer = min(answer , abs(snowman1 - snowman2));
                if(answer == 0) break;
                
                if(snowman1 < snowman2) second--;
                else first++;
            }
        }
    }

    cout << answer << endl;
    
    return 0;
}
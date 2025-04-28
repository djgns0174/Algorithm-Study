#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

#define endl "\n"

using namespace std;

/*

    두 용액 - 2470

    [이분탐색]
    1. 음의 값과 양의 값을 나눈다.
    2. 완전탐색으로 값을 하나 선택한다.
        1. 값이 음수면 양의값에서 이분탐색으로 더했을 때 0과 근접한 값 탐색
        2. 값이 양수면 음의 값에서 이분탐색으로 더했을 때 0과 근접한 값 탐색
            1. 더했을 때 0이면 프로그램 종료
            2. 음수면 start = key + 1
            3. 양수면 end = key - 1
        3. 이분 탐색이 종료되면 혼합된 값과 비교해서 더 작으면 두 값을 넣는다.

    [시간복잡도]
    n(완전탐색으로 값 하나 선택) * logn(이분탐색으로 0 근접한 값 탐색)
    = nlogn 으로 시간통과

    [틀린 이유]
    - 음의 값이나 양의 값만 입력되었을 경우
    - 양의 값만 더했을 때 0과 근접한 경우
        - 반례 : -100 1 2 로 입력이 들어올때 정답은 1 2 가 되어야됨.

    [해결방법]
    Answer 우선순위 큐에 minus, plus 두 vector 모두 가장 적은 값 둘을 더한값을 넣고 한다. 후에 우선순위 큐에서 삽입할때 정렬이 되어 절대값이 가장 작은 경우가 정답으로 나온다.

*/

int main(void){

    int n;
    cin >> n;

    vector<int>minus;
    vector<int>plus;
    priority_queue<pair<int, pair<int, int>>> answer;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;

        if(input < 0) minus.push_back(input);
        else plus.push_back(input);
    }

    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    if(minus.size() >= 2)
    {
        answer.push({abs(minus[minus.size()-2] + minus[minus.size()-1]), {minus[minus.size()-2], minus[minus.size()-1]}});
    }

    if(plus.size() >= 2)
    {
        answer.push({abs(plus[0] + plus[1]), {plus[0], plus[1]}});
    }

    for(int i=0; i<minus.size(); i++)
    {
        int minusValue = minus[i];
    
        int start = 0;
        int end = plus.size() - 1;

        if(end < 0) break;

        while(start <= end)
        {
            int key = (start + end) / 2;
            int plusValue = plus[key];
            int sum = plusValue + minusValue;

            if(sum == 0)
            {
                cout << minusValue << " " << plusValue << endl;
                return 0;
            }
            else if(sum < 0) start = key + 1;
            else end = key - 1;

            answer.push({abs(sum), {minusValue, plusValue}});
        }
    }

    while(!answer.empty())
    {
        if(answer.size() == 1)
        {
            cout << answer.top().second.first << " " << answer.top().second.second << endl;
            return 0;
        }
        else answer.pop();
    }

    return 0;
}

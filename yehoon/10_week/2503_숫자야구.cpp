#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    숫자 야구 - 2503

    [구현] 
    1. 모든 경우의 수(후보)를 나열한다. 
    2. 후보들을 질문과 비교해서 소거한다. 
        1. 스트라이크 개수만큼 후보들의 각 자리가 스트라이크 되는지 판별
        2. 볼 개수만큼 후보들이 숫자를 가지고 있는지(자리는 같으면 안됨)
    3. 최종적으로 남은 후보들의 개수를 출력한다.

    [시간복잡도]
    최악의 경우 
    N * 9*8*7(후보개수) * 9*8*7(후보 지우는 비용) = 25,401,600 으로 통과
*/

int main(void)
{
    int n; cin >> n;

    vector<pair<int, pair<int,int>>> arr(n);
    for(int i=0; i<n; i++)
    {
        int num, s, b;
        cin >> num >> s >> b;
        arr[i] = {num, {s, b}};
    }

    vector<int> candidates;
    // 모든 후보 나열
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            for(int k=1; k<=9; k++)
            {
                if(i==j || i==k || j==k) continue;
                candidates.push_back((i * 100) + (j * 10) + k);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        int num = arr[i].first;
        int s = arr[i].second.first;
        int b = arr[i].second.second;

        // 첫째자리 둘째자리 셋째자리 구하기
        int num_first = num / 100;
        int num_second = num % 100 / 10;
        int num_third = num % 100 % 10;

        for(int j=candidates.size()-1; j>=0; j--)
        {
            // 첫째자리 둘째자리 셋째자리 구하기
            int candidate_first = candidates[j] / 100;
            int candidate_second = candidates[j] % 100 / 10;
            int candidate_third = candidates[j] % 100 % 10;

            // 스트라이크 볼 개수 카운트
            int strike_count = 0; int ball_count = 0;
            if(num_first == candidate_first) strike_count++;
            if(num_second == candidate_second) strike_count++;
            if(num_third == candidate_third) strike_count++;

            if(num_first == candidate_second || num_first == candidate_third) ball_count++;
            if(num_second == candidate_first || num_second == candidate_third) ball_count++;
            if(num_third == candidate_first || num_third == candidate_second) ball_count++;

            // 스트라이크 볼 개수가 맞지 않다면 후보 제외
            if(s != strike_count || b != ball_count)
            {
                auto it = find(candidates.begin(), candidates.end(), candidates[j]);
                candidates.erase(it);
            }
        }
    }

    cout << candidates.size() << endl;

    return 0;
}
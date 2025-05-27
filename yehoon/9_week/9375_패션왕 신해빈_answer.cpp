#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define endl "\n"

using namespace std;

/*
    패션왕 신해빈

    [조합]
    하나만 입었을때 경우의 수 + 두개 입었을때 경우의 수 + … + n개 입었을때 경우의수
    = 1개 선택했을때 조합 + 2개 선택했을때 조합 + … + n개 선택했을때 조합
    => 시간초과

    [순열]
    순열로 옷을 안입었을때 포함 - 1 
    => 선형시간
*/

int main(void)
{
    int t; cin >> t;
    vector<int>answers;

    for(int i=0; i<t; i++)
    {
        int n; cin >> n;
        int answer = 1;

        map<string,int> m;
        vector<int> value;

        for(int j=0; j<n; j++)
        {
            string name, kind;
            cin >> name >> kind;

            m[kind]++;
        }

        for (const auto& pair : m) value.push_back(pair.second);

        for(int j:value) answer *= (j+1);

        answers.push_back(--answer);
    }

    for(int i:answers) cout << i << endl;
}
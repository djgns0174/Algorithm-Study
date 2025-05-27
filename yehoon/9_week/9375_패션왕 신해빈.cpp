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

int answer;

void combination(int start, int n, int r, vector<int>comb, vector<int>value)
{
    if(r == 0)
    {
        int tmp = 1;
        for(int i=0; i<comb.size(); i++) tmp *= comb[i];

        answer += tmp;
    }

    else 
    {
        for(int i=start; i<n; i++)
        {
            comb.push_back(value[i]);
            combination(i+1, n, r-1, comb, value);
            comb.pop_back(); 
        }
    }
}

int main(void)
{
    int t; cin >> t;
    vector<int>answers;

    for(int i=0; i<t; i++)
    {
        int n; cin >> n;
        answer = 0;

        map<string,int> m;
        vector<int> value;

        for(int j=0; j<n; j++)
        {
            string name, kind;
            cin >> name >> kind;

            m[kind]++;
        }

        for (const auto& pair : m) value.push_back(pair.second);

        int kindNumber = value.size();
        for(int j=1; j<=kindNumber; j++)
        {
            vector<int> comb;
            combination(0, kindNumber, j, comb, value);
        }

        answers.push_back(answer);
    }

    for(int i:answers) cout << i << endl;
}
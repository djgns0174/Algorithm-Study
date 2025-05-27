#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    암호 만들기 - 1759 

    [백트래킹]
    재귀함수
        만약 깊이와 M이 동일하다면 
            모음이 한개인지, 자음이 최소 두개인지 반복문을 돌려서 확인한다.
            위의 조건을 만족하면 저장해두었던 벡터의 값을 모두 출력한다.
        그렇지 않다면 
            현재값을 벡터에 저장한다. 
            인자를 다음과 같이 설정하고 재귀함수를 호출한다.
            인자 : 
            1. start = 1 증가 시킴
            2. Depth = 1 증가 시킴

    [백트래킹 시간복잡도]
    반복문을 수행하는 횟수(Combination) * l 으로 
    최악의 경우 15C7 * 15 = 6435×15 = 96,525 으로 시간 통과
*/

int l, c;
vector<string>arr;

void func(int start, int depth, vector<string>v)
{
    if(depth == l)
    {
        bool b1 = false;
        bool b2 = false;
        int cnt = 0;
        for(string s : v) 
        {
            if(s == "a" || s == "e" || s == "i" || s == "o" || s == "u" ) b1 = true;

            else cnt++;
        }

        if(cnt >= 2) b2 = true;

        if(b1 && b2)
        {
            for(string s : v) cout << s;
            cout << endl;
        }
    }

    else
    {
        for(int i=start; i<c; i++)
        {
            v.push_back(arr[i]);
            func(i+1, depth+1, v);
            v.pop_back();
        }
    }
}

int main(void)
{
    cin >> l >> c;

    for(int i=0; i<c; i++)
    {
        string input; cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    vector<string> v;
    func(0, 0, v);
    
    return 0;
}
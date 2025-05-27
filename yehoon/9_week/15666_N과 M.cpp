#include<iostream>
#include<set>
#include<vector>

#define endl "\n"

using namespace std;

/*
    N과 M - 15666

    [백트래킹]
    재귀함수
        만약 깊이와 M이 동일하다면 저장해두었던 벡터의 값을 모두 출력한다.
        그렇지 않다면 현재값을 벡터에 저장하고 재귀함수를 호출하는데 인자에
        start는 현재값으로 두고(어차피 for문으로 증가해서 전달됨) 깊이만 증가시킨다. 

    [백트래킹 시간복잡도]
    n(for문으로 재귀함수 호출) * n(집합에서 벡터에 넣을 값 찾기) 
    최대 입력수 10000^2 = 100,000,000 으로 통과
*/

int n, m;
set<int> s;

void func(int start, int depth, vector<int> v)
{
    if(depth == m) 
    {
        for(int i:v) cout << i << " ";
        cout << endl;
    }

    else
    {
        for(int i=start; i<s.size(); i++)
        {
            auto it = next(s.begin(), i);
            v.push_back(*it);
            func(i, depth+1, v);
            v.pop_back();
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        int input; cin >> input;
        s.insert(input);
    }

    vector<int> v;
    func(0, 0, v);
}
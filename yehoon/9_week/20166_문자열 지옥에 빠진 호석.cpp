#include<iostream>
#include<vector>
#include<unordered_map>
#define endl "\n"

using namespace std;

unordered_map<string, int> freq;

/*
문자열 지옥에 빠진 호석 - 20166

✅ 1. 좋아하는 문자열을 기준으로 DFS 수행하는 방식
    방식 설명:좋아하는 문자열 하나하나에 대해, 격자판의 모든 칸에서 시작하여DFS로 문자열이 만들어지는지를 확인합니다.
    시간복잡도:O(k × n × m × 8^L)
        k: 좋아하는 문자열 개수
        n × m: 격자판의 모든 시작점에서 탐색
        8^L: 각 문자의 다음 문자를 만들기 위해 8방향으로 최대 L(최대 문자열 길이) 만큼 탐색
    단점 : 중복되는 경로가 매우 많아 시간 초과 발생 가능성이 높음

✅ 2. 해시맵(map)을 활용해 모든 가능한 문자열을 미리 세는 방식
    방식 설명:격자판의 모든 칸에서 DFS를 수행하면서,길이 1부터 최대 5까지의 모든 문자열 조합을 만들어서각각의 문자열이 얼마나 나오는지를 해시맵(map)에 기록해 둡니다.이후, 좋아하는 문자열에 대해 map에서 횟수만 바로 조회하면 됩니다.
    시간복잡도:O(n × m × 8^L)
        n × m: 격자판의 모든 칸에서 시작
        8^L: 문자열 길이 최대 L(보통 5)까지의 모든 경로 탐색
        k: 문자열 조회는 O(1)이므로 별도로 추가하지 않음
    장점:중복되는 경로를 한 번만 탐색해서 모두 저장해두므로 훨씬 빠르고 효율적

*/

int n, m, k;
vector<vector<char>>arr;

int dx[8] = {0,0,1,1,-1,-1,-1,1};
int dy[8] = {1,-1,0,1,0,-1,1,-1};

void func(pair<int,int>p, string s, int depth)
{
    // if(depth > 5) return; 
    // 틀린이유 : 처음에 깊이를 0으로 시작하기 때문에 -1해서 종료조건을 설정해야된다. 
    //          안 그러면 한번 더 8방향으로 탐색을 진행하므로 시간초과가 발생한다.
    if(depth > 4) return;  

    freq[s]++;

    for(int i=0; i<8; i++)
    {
        int nextI = (p.first + dx[i]) % n;
        int nextJ = (p.second + dy[i]) % m;
        if(nextI == -1) nextI = n-1;
        if(nextJ == -1) nextJ = m-1;

        pair<int,int> p = {nextI, nextJ};

        func(p, s + arr[nextI][nextJ], depth + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    arr = vector<vector<char>>(n, vector<char>(m));

    for(int i=0; i<n; i++)
    {
        string input; cin >> input;
        for(int j=0; j<m; j++) arr[i][j] = input[j];
    }
    
    vector<string> like(k);
    vector<int> answers;
    for(int i=0; i<k; i++) cin >> like[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            string s = "";
            pair<int,int> p = {i,j};
            func(p, s+arr[i][j], 0);
        }
    }

    for(int i=0; i<k; i++)
    {
        cout << freq[like[i]] << endl;
    }
    
    return 0;
}
#include <iostream>
#include <map>
#include <vector>

using namespace std;

static char arr[11][11];

int N, M, K;
map<string, int> m;

void DFS(int i, int j, int depth, string s);

int di[8] = {-1 ,1, 0, 0, 1, 1, -1, -1};
int dj[8] = {0, 0, -1, 1, 1, -1, 1, -1};


int main(){
    cin >> N >> M >> K;
   
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }
   
    vector<string> v;
    for(int i=0;i<K;i++){
        string str;
        cin >> str;
       
         // 신이 좋아하는 문자열은 중복될 수 있기 때문에 따로 벡터에 담아 둠 map만 쓰면 중복 고려가 안됨 
        v.push_back(str);
        m.insert({str, 0});
    }
   
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            DFS(i, j, 1, "");
        }
    }
   
   
    // 정답 출력
    for(int i=0;i<K;i++){
        cout << m[v[i]] << "\n";
    }
   
    return 0;
}

void DFS(int i, int j, int depth, string s) {
    if(depth > 5) return;
   
    s += arr[i][j];
    if(m.find(s) != m.end()) {
        m[s]++;
    }
   
    for(int d=0;d<8;d++){
        int next_i = i + di[d];
        int next_j = j + dj[d];
       
        // 환형 이동 처리
        if(next_i == 0) next_i = N;
        if(next_i == N+1) next_i = 1;
        if(next_j == 0) next_j = M;
        if(next_j == M+1) next_j = 1;
       
        DFS(next_i, next_j, depth + 1, s);
    }
}

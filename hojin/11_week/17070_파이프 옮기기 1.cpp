#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define endl "\n"

/*
check~ 함수가 모든 경우를 고려하지 않아서 
함수가 종료될 때 쓰레기값을 반환하는 경우가 생겼음
경계를 넘지도 않고, 빈 공간이 아닌 경우가 고려되지 않아 쓰레기값이 return되어
실행환경과 채점환경의 출력 차이가 발생했음
*/


int n;
int cnt = 0;
vector<vector<int> > mat;

bool checkHor(pair<int, int> front){
    if (front.second+1 > n) return false;
    else if (mat[front.first][front.second+1] == 0) return true;
    return false;
}

bool checkVer(pair<int, int> front){
    if (front.first+1 > n) return false;
    else if (mat[front.first+1][front.second] == 0) return true;
    return false;
}

bool checkDiag(pair<int, int> front){
    if (front.first+1 > n || front.second+1 > n) return false;
    else if 
        (mat[front.first+1][front.second] == 0 &&
        mat[front.first][front.second+1] == 0 &&
        mat[front.first+1][front.second+1] == 0) 
        return true;
    return false;
}

void dfs(int shape, pair<int, int> front){
    if (front.first == n && front.second == n){
        cnt++;
        return;
    }

    // 파이프 배치 가로
    if (shape == 0){ 
        if (checkHor(front)){ // 가로로 이동
            dfs(0, {front.first, front.second+1});
        }
        if (checkDiag(front)){ // 대각선으로 이동
            dfs(2, {front.first+1, front.second+1});
        }
    }
     // 파이프 배치 세로
    else if (shape == 1){
        if (checkVer(front)){ // 세로로 이동
            dfs(1, {front.first+1, front.second});
        }
        if (checkDiag(front)){ // 대각선으로 이동
            dfs(2, {front.first+1, front.second+1});
        }
    }
    // 파이프 배치 대각선
    else if (shape == 2){
        if (checkHor(front)){ // 가로로 이동
            dfs(0, {front.first, front.second+1});
        }
        if (checkVer(front)){ // 세로로 이동
            dfs(1, {front.first+1, front.second});
        }
        if (checkDiag(front)){ // 대각선으로 이동
            dfs(2, {front.first+1, front.second+1});
        }
    }

    return;
}

int main() {
    cin >> n;
    mat.resize(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> mat[i][j];
        }
    }

    dfs(0, {1, 2});

    cout << cnt;

    return 0;
}
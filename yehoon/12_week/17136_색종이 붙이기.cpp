#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define endl "\n"

using namespace std;

/*
    색종이 붙이기
    
    [브루트포스]
    1. 1인 부분을 찾는다.
    2. 1인 부분부터 어떤 크기의 색종이를 붙여야 되는지 1~5까지 확인한다.
    3. 색종이의 크기가 확인되는대로 색종이를 붙인다.
    4. 재귀함수 호출
        1. 호출 전에는 cnt++, 색종이 붙이기, 색종이 개수 감수
        2. 호출 후에는 cnt—, 색종이 떼기, 색종이 개수 증가
    5. 마지막 열에 도달했다면 answer 업데이트
    6. 이미 answer보다 cnt값이 크면 return (가지치기)
*/
vector<vector<int>> arr(10, vector<int>(10));
int paper[6] = {0, 5, 5, 5, 5, 5}; // 각 색종이 남은 개수 (1~5)
int answer = INT_MAX; // 최소 색종이 개수

// (y,x) 위치에 size 크기 색종이를 붙일 수 있는지 확인
bool canAttach(int y, int x, int size) {
    if (y + size > 10 || x + size > 10) return false;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

// (y,x) 위치에 size 크기 색종이를 붙이거나 떼기
void setPaper(int y, int x, int size, int state) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            arr[i][j] = state;
        }
    }
}

void dfs(int y, int x, int cnt) {
    // 백트래킹: 이미 찾은 답보다 크면 종료
    if (cnt >= answer) return;
    
    // 마지막 행까지 다 확인한 경우
    if (y == 10) {
        answer = min(answer, cnt);
        return;
    }
    
    // 다음 행으로 이동
    if (x == 10) {
        dfs(y + 1, 0, cnt);
        return;
    }
    
    // 현재 칸이 0이면 다음 칸으로
    if (arr[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }
    
    // 큰 색종이부터 시도
    for (int size = 5; size >= 1; size--) {
        if (paper[size] == 0) continue;
        if (!canAttach(y, x, size)) continue;
        
        setPaper(y, x, size, 0);
        paper[size]--;
        
        dfs(y, x + size, cnt + 1);
        
        setPaper(y, x, size, 1);
        paper[size]++;
    }
}

int main() {
    // 입력 받기
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(0, 0, 0);
    
    if (answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;
    
    return 0;
}
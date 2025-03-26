#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int arr[1001][1001];         // 맵 정보
int cost[1001][1001];        // 벽을 부수지 않은 경우의 최단 거리
int wall_cost[1001][1001];   // 벽을 부순 경우의 최단 거리

/* 처음에 int 자료형 배열을 3개 선언하니까 segmentation fault가 났음. 한 프로그램에서 할당된 스택메모리의 크기는 8~16MB정도라고 함. 내가 사용한 메모리크기는 13MB니까 가능성 있음. -> short로 바꾸니 오류 안남(13 -> 7MB) */
// short배열을 사용하니 오버플로우 나서 int배열로 바꿈.

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
            cost[i][j] = wall_cost[i][j] = -1;  // 방문하지 않은 상태를 -1로 설정
        }
    }

    queue<tuple<int, int, int, int>> q; // (y, x, 벽 부숨 여부, 현재 거리)
    q.push({0, 0, 0, 1});  // 시작점 (1,1)은 거리 1로 시작
    cost[0][0] = 1;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int y, x, broken, dist;
        tie(y, x, broken, dist) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (arr[ny][nx] == 0) {  // 벽이 아닐 때
                if (broken == 0 && cost[ny][nx] == -1) {  // 벽을 부수지 않고 방문
                    cost[ny][nx] = dist + 1;
                    q.push({ny, nx, 0, dist + 1});
                } 
                else if (broken == 1 && wall_cost[ny][nx] == -1) {  // 벽을 부수고 방문
                    wall_cost[ny][nx] = dist + 1;
                    q.push({ny, nx, 1, dist + 1});
                }
            } 
            else if (arr[ny][nx] == 1 && broken == 0) {  // 벽일 때, 처음 부수는 경우
                wall_cost[ny][nx] = dist + 1;
                q.push({ny, nx, 1, dist + 1});
            }
        }
    }

    int result1 = cost[n - 1][m - 1];
    int result2 = wall_cost[n - 1][m - 1];

    if (result1 == -1 && result2 == -1) cout << -1;
    else if (result1 == -1) cout << result2;
    else if (result2 == -1) cout << result1;
    else cout << min(result1, result2);

    return 0;
}

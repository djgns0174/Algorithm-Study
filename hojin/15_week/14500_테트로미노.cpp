#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int n, m;
vector<vector<int> > mat;
vector<vector<bool> > visited;

bool isValid(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= m ){
        return false;
    }
    else return true;
}

//  ㅗ를 제외한 테트로미노의 합
int calSum(int y, int x, int tetroNum, int sum){
    if (tetroNum == 4) return sum;
    int maxSum = 0;
    visited[y][x] = true;
    
    // 위에서 부터 탐색하기 때문에 위로 가는 방향은 제외하여 탐색
    int dx[3] = {-1, 1, 0}; 
    int dy[3] = {0, 0, 1};
    for (int k=0; k<3; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!isValid(ny, nx) || visited[ny][nx]) continue;
        
        int tmp = calSum(ny, nx, tetroNum+1, sum+mat[ny][nx]);
        maxSum = max(maxSum, tmp);
    }
    visited[y][x] = false;

    return maxSum;
}

// ㅗ 모양의 테트로미노의 합
int calExcepSum(int y, int x){ 
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int sum = mat[y][x];
    int maxSum = sum;

    // 4방향 모두 더함
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid(ny, nx)){
            sum += mat[ny][nx];
        }
    }

    // 4방향 중 하나를 뺌
    for (int j=0; j<4; j++){
        int ny = y + dy[j];
        int nx = x + dx[j];
        if (isValid(ny, nx)){
            maxSum = max(maxSum, sum - mat[ny][nx]);
        } else {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    cin >> n >> m;

    mat.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int y=0; y<n; y++){
        for (int x=0; x<m; x++){
            cin >> mat[y][x];
        }
    }

    int answer = -1;
    for (int y=0; y<n; y++){
        for (int x=0; x<m; x++){
            answer = max(answer, calSum(y, x, 1, mat[y][x]));
            answer = max(answer, calExcepSum(y, x));
        }
    }

    cout << answer;

    return 0;
}
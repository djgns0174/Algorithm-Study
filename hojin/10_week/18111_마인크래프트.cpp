#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int> > mat(n, vector<int>(m));

    int minH = 256;
    int maxH = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> mat[i][j];
            minH = min(mat[i][j], minH);
            maxH = max(mat[i][j], maxH);
        }
    }
    int minTime = 500*500*256;
    int resultH = -1;

    for(int k=minH; k<=maxH; k++){
        // debug
        // cout << "k: " << k << endl;

        bool possible = true; // 이중 for문 탈출 플래그
        int newB = b;
        int time = 0;
        for(int i=0; i<n; i++){
            if (!possible) break;
            
            for (int j=0; j<m; j++){
                if (mat[i][j] >= k){ // 목표 높이보다 높으면
                    int dif = mat[i][j]-k;
                    time += 2*dif;
                    newB += dif;
                }
                else { // 목표 높이보다 낮거나 같으면
                    int dif = k-mat[i][j];
                    time += dif;
                    newB -= dif;
                }
            }
        }

        if (time <= minTime && newB >= 0){ // 최소시간이며 블록이 충분할 경우
            minTime = time;
            resultH = k;
            
            // debug
            // cout << "update!" << endl;
            // cout << minTime << ' ' << resultH << endl;
        }
    }

    cout << minTime << ' ' << resultH;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int n, m;

bool checkBound(int i, int j){
    if (i < 0 || i > n-1) return false;
    if (j < 0 || j > m-1) return false;
    else return true;
}

int main() {
    int d, cnt, ans;
    cin >> n >> m >> d;
    ans = -1;
    vector<vector<int> > realMat(n, vector<int>(m));
    vector<vector<int> > mat(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> realMat[i][j];
        }
    }

    vector<int> archor(3);
    // 궁수 배치 (브루탈 포스)
    for (int i=0; i<m; i++){
        archor[0] = i;
        for (int j=i+1; j<m; j++){
            archor[1] = j;
            for (int k=j+1; k<m; k++){
                archor[2] = k;
                cnt = 0;
                mat = realMat;
                // 턴이 진행될 때마다
                for (int turn=0; turn<n; turn++){
                    int near = n-1-turn; // 성과 가장 가까운 열 번호 
                    vector<pair<int, int> > shooted(3, {-1, -1});
                    for (int arch=0; arch<3; arch++){
                        bool found = false;
                        // 거리 1짜리 확인
                        // cout << "checking front: " << near << ", " << archor[arch] << ", arch: " << arch << endl;
                        if (mat[near][archor[arch]] == 1){
                            shooted[arch] = {near, archor[arch]};
                        } else {
                            for (int dist=2; dist<=d; dist++){ // 거리 2부터 탐색 범위까지
                                if (found) break;
                                for (int distSeq=0; distSeq<2*dist; distSeq++){
                                    // 궁수 탐색 범위 좌측
                                    if (distSeq < dist){
                                        if (checkBound(near-distSeq, archor[arch]-dist+1+distSeq)){
                                            // cout << "checking left: " << near-distSeq << ", " << archor[arch]-dist+1+distSeq << ", arch: " << arch << endl;
                                            if (mat[near-distSeq][archor[arch]-dist+1+distSeq]){
                                                shooted[arch] = {near-distSeq, archor[arch]+distSeq-dist+1};
                                                found = true;
                                                break;
                                            }
                                        }
                                    }
                                    else {
                                        // 궁수 탐색 범위 우측
                                        if (checkBound(near-(2*dist)+distSeq+1, archor[arch]-dist+distSeq)){
                                            // cout << "checking right: " << near-(2*dist)+distSeq+1 << ", " << archor[arch]-dist+1+distSeq << ", arch: " << arch << endl;
                                            if (mat[near-(2*dist)+distSeq+1][archor[arch]-dist+distSeq]){
                                                shooted[arch] = {near-(2*dist)+distSeq+1, archor[arch]-dist+distSeq};
                                                found = true;
                                                break;
                                            }
                                        }                                        
                                    }
                                    
                                }
                                
                                
                            }  
                        }
                        
                    }

                    // 선택된 적 제거
                    for (int arch=0; arch<3; arch++){
                        if (shooted[arch].first != -1){
                            if (mat[shooted[arch].first][shooted[arch].second] != 0){
                                mat[shooted[arch].first][shooted[arch].second] = 0;
                                // cout << "eliminated! (" << shooted[arch].first << ", " << shooted[arch].second << ") at turn " << turn << " by arch " << arch << endl;
                                cnt++;
                                // cout << "cnt: " << cnt << endl;
                            }
                        }

                    }
                }
                
                ans = max(ans, cnt);
                // cout << "archor located: " << archor[0] << ", " << archor[1] << ", " << archor[2] << " -> cnt: " << cnt << endl;
            }
        }
    }

    cout << ans;

    return 0;
}
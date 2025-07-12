#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int n;
int maxScore = -1;

void playGame(vector<int> order, vector<vector<int> > player){
    int score = 0;
    int k = 0;
    for (int j=0; j<n; j++){ // 이닝
        vector<bool> ru(3, false);
        int outCnt = 0;
        for (; outCnt<3; k++){ // 3아웃 될 때까지
            if (player[j][order[k%9]] == 0){ // 아웃 처리
                outCnt++;
                continue;
            }
            // cout << "player: " << k%9 << ", ining: " << j << endl;
            bool isJinru = false;
            for (int l=2; l>=0; l--){ // 3루부터 1루까지 도루
                if (l+player[j][order[k%9]] >= 3 && ru[l]){
                    ru[l] = false;
                    score++;
                }
                else if (l+player[j][order[k%9]] < 3 && ru[l]){
                    ru[l] = false;
                    ru[l+player[j][order[k%9]]] = true;
                }
            }

            // 타자 도루
            if (player[j][order[k%9]] == 4) score++;
            else {ru[player[j][order[k%9]] -1]  = true;}
        }
    }

    // if (score >= maxScore){
    //     cout << "order: ";
    //     for (int i=0; i<9; i++){
    //         cout << order[i] << " ";
    //     }
    //     cout << endl;
    // }
    maxScore = max(maxScore, score);
}

void batch(vector<int> order, int orderNum,  vector<vector<int> > player, vector<bool> batchedPlayer){
    if (orderNum == 3){ // 4번째 순서는 넘어감
        batch(order, 4, player, batchedPlayer);
    }

    if (orderNum == 9){ // 순서 모두 배치됨
        playGame(order, player);
        return;
    }

    for (int i=1; i<9; i++){ // 1번을 제외한 모든 선수에 대해서
        if (!batchedPlayer[i]){ // 선수가 배치되지 않았으면
            order[orderNum] = i; // 선수 배치
            batchedPlayer[i] = true;                
            batch(order, orderNum+1, player, batchedPlayer);
            batchedPlayer[i] = false;            
        }

    }

}



int main() {
    
    cin >> n;
    vector<vector<int> > player(n, vector<int>(9));
    for (int i=0; i<n; i++){
        for (int j=0; j<9; j++){
            cin >> player[i][j];
        }
    }
    
    vector<int> order(9);
    order[3] = 0;
    vector<bool> batchedPlayer(9, false);
    batchedPlayer[0] = true;
    
    batch(order, 0, player, batchedPlayer);
    
    cout << maxScore;

    return 0;
}
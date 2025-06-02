#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    int n;
    cin >> n;
    vector<vector<int> > quest(n, vector<int>(3));
    vector<int> questStrike(n);
    vector<int> questBall(n);
    int cnt = 0;
    
    int input;
    for (int i=0; i<n; i++){
        cin >> input;
        cin >> questStrike[i];
        cin >> questBall[i];

        quest[i][0] = input / 100;
        quest[i][1] = (input % 100) / 10;
        quest[i][2] = input % 10;
    }

    for (int i=12; i<999; i++){ // 모든 수에 대해서 수행 (브루트 포스)
        vector<int> number(3);
        number[0] = i / 100;
        number[1] = (i % 100) / 10;
        number[2] = i % 10;
        int strike = 0;
        int ball = 0;
        bool possible = true;

        if (number[0] == 0 || number[1] == 0 || number[2] == 0) continue; // 0은 안됨
        if (number[0] == number[1] || number[0] == number[2] ||  number[1] == number[2]) continue; // 숫자가 서로 다름

        for (int j=0; j<n; j++){
            int strike = 0;
            int ball = 0;
            
            for (int k=0; k<3; k++){
                if (number[k] == quest[j][k]) strike++;

                if (number[k] == quest[j][(k+1)%3] || number[k] == quest[j][(k+2)%3]) ball++;
            }

            if (strike != questStrike[j] || ball != questBall[j]) {
                possible = false;
                break;
            }

        }

        if (possible) {
            cnt++;
            // debug
            // cout << i << " is possible" << endl;
        }
    }
    
    cout << cnt;

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>

using namespace std;

int main(void){

    // 입력받기
    int n, z, m;
    cin >> n >> z >> m;

    // 길 설정 : 장애물(0), 길(1), 목적지(2)
    vector<int> arr(n+1);
    for(int i=1; i<arr.size(); i++){
        arr[i] = 1;
        if(i == z) arr[i] = 2;
    }

    // 장애물 입력받고 설정
    for(int i=0; i<m; i++){
        int obstacle;
        cin >> obstacle;
        arr[obstacle] = 0;
    }

    // 핵심 로직
    for(int i=1; i<n; i++){
        int cur = 1;
        vector<bool> visit(n+1, false);
        while(1){
            // 방문했다면
            if(visit[cur]) break;

            // 방문 체크
            visit[cur] = true;
            cur += i;

            if(cur > n){
                cur -= n;
            }

            // 목적지라면
            if(arr[cur] == 2){
                cout << i << endl;
                return 0;
            }

            // 장애물이라면
            if(arr[cur] == 0){
                break;
            }
        }
    }
}
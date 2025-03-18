#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin >> n;

    // 입력받기
    vector<vector<int> > arr(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    // 덩치 더 큰사람 수 0으로 초기화
    for(int i=0; i<n; i++){
        arr[i][2] = 0;
    }

    // 완전탐색
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            // 덩치 더 큰사람이 있다면 카운트
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]){
                arr[i][2]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i][2] + 1 << " ";
    }
}
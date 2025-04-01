#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int arr[1001];
static vector<vector<int>> result(1001);

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    
    for(int i=1;i<=N;i++){
        result[i].push_back(arr[i]); // 첫 번째 원소 추가
        for(int j=1;j<i;j++){ // 현재 원소보다 앞에 있는 원소 중에서
            if(arr[j] < arr[i] && result[j].size() + 1 > result[i].size()) { // 현재 원소보다 작으면서 부분 수열의 크기가 더 길다면
                result[i] = result[j]; // 해당 부분 수열을 가져온다
                result[i].push_back(arr[i]); // 해당 부분 수열에 현재 원소(마지막 원소)를 푸쉬한다
            }
        }
    }
    
    // 가장 긴 길이를 가진 곳의 인덱스 찾기
    int maxIndex = 1;
    for(int i=2;i<=N;i++){
        if(result[maxIndex].size() < result[i].size()) {
            maxIndex = i;
        }
    }
    
    int size = result[maxIndex].size();
    cout << size << "\n";
    
    for(int i=0;i<size;i++){
        cout << result[maxIndex][i] << " ";
    }
}
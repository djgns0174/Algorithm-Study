#include <iostream>
#include <algorithm>

using namespace std;

static int N, M;

static int arr[8];
static int answer[8];

void DFS(int start, int count);

int main() {
    cin >> N >> M;
   
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
   
    sort(arr, arr + N);
   
    DFS(0, 0);
   
    return 0;
}



void DFS(int start, int count) {
   
    if(count == M) {
        for(int i=0;i<M;i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
   
   
    int pre = 0;
    for(int i = start; i < N; i++){
        if(pre != arr[i]) {
            pre = arr[i];
            answer[count] = arr[i];
            DFS(i, count + 1);
        }
    }
}
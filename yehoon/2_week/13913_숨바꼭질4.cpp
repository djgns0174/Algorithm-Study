#include<iostream>
#include<queue>

using namespace std;

// 틀린이유 -> 이전 모든 경로값 저장하다가 시간초과남
queue<pair<int, int> > q;
bool visited[100001] = {false,};
int arr[100001] = {0,};

void push(int curr_n, int curr_cost){
    if(curr_n*2 <= 100000 && !visited[curr_n*2] && curr_n!=0){
        q.push(make_pair(curr_n*2, curr_cost+1));

        //이전 경로값 세팅
        arr[curr_n*2] = curr_n;

        visited[curr_n*2] = true;
    }

    if(curr_n-1 >= 0 && !visited[curr_n-1]){
        q.push(make_pair(curr_n-1, curr_cost+1));

        //이전 경로값 세팅
        arr[curr_n-1] = curr_n;

        visited[curr_n-1] = true;
    }

    if(curr_n+1 <= 100000 && !visited[curr_n+1]){
        q.push(make_pair(curr_n+1, curr_cost+1));

        //이전 경로값 세팅
        arr[curr_n+1] = curr_n;

        visited[curr_n+1] = true;
    }
}

int main(void){

    int n, k;
    cin >> n >> k;

    q.push(make_pair(n,0));
    visited[n] = true;

    arr[n] = -1;

    while(!q.empty()){
        int curr_n = q.front().first;
        if(curr_n == k) break;
        int curr_cost = q.front().second;
        q.pop();

        push(curr_n, curr_cost);
    }

    cout << q.front().second << endl;

    //이전 경로값 출력
    vector<int> answer;
    answer.push_back(k);
    int tmp = arr[k];
    while(tmp >= 0){
        answer.push_back(tmp);
        tmp = arr[tmp];
    }

    for(int i=answer.size()-1; i>=0; i--){
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}
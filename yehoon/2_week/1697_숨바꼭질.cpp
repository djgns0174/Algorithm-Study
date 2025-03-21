#include<iostream>
#include<queue>

using namespace std;

queue<pair<int, int>  > q;
bool visited[100001] = {false,};

/*
    5 17
    1. 5와 cost 0을 큐에 먼저 넣는다.
    2. 큐에서 요소를 빼고 해당 요소의 -1, +1, *2 를 진행한다.
    3. 진행해서 연산된 값이 방문하지 않은 값이라면 큐에 삽입한다.
    4. 목적지에 도달할때까지 반복한다.
*/

void push(int curr_n, int curr_cost){

    // 틀린 이유 -> !visited[curr_n-1] && curr_n-1 >= 0 을 수행할때 먼저 배열의 초과값을 접근하기 때문.
    // 방문하지 않고 범위를 넘어서지 않는다면 큐에 넣는다.
    if(curr_n-1 >= 0 && !visited[curr_n-1]) {
        q.push(make_pair(curr_n-1, curr_cost+1));
        // 방문 처리
        visited[curr_n-1] = true;
    }

    if(curr_n+1 <= 100000 && !visited[curr_n+1]){
        q.push(make_pair(curr_n+1, curr_cost+1));
        // 방문 처리
        visited[curr_n + 1] = true;

    }

    if(curr_n*2 <= 100000 && !visited[curr_n*2]) {
        q.push(make_pair(curr_n*2, curr_cost+1));
        // 방문 처리
        visited[curr_n * 2] = true;
    }

    return;
}

int main(void){

    int n, k;
    cin >> n >> k;

    // 초기값 큐에 삽입
    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()){
        int curr_n = q.front().first;

        // 목적지에 도달한다면
        if(curr_n == k) break;

        int curr_cost = q.front().second;
        q.pop();

        push(curr_n, curr_cost);
    }

    cout << q.front().second << endl;
    
    return 0;
}
#include<iostream>
#include<queue>

using namespace std;

queue<pair<int, int> > q;
bool visited[100001] = {false,};

// 1697 숨바꼭질 문제와 유사하나 *2의 curr_cost 값을 그대로 뒀음

void push(int curr_n, int curr_cost){
    if(curr_n*2 <= 100000 && !visited[curr_n*2]){
        q.push(make_pair(curr_n*2, curr_cost));
        visited[curr_n*2] = true;
    }

    if(curr_n-1 >= 0 && !visited[curr_n-1]){
        q.push(make_pair(curr_n-1, curr_cost+1));
        visited[curr_n-1] = true;
    }

    if(curr_n+1 <= 100000 && !visited[curr_n+1]){
        q.push(make_pair(curr_n+1, curr_cost+1));
        visited[curr_n+1] = true;
    }
}

int main(void){

    int n, k;
    cin >> n >> k;

    q.push(make_pair(n,0));

    while(!q.empty()){
        int curr_n = q.front().first;
        if(curr_n == k) break;
        int curr_cost = q.front().second;
        q.pop();

        push(curr_n, curr_cost);
    }

    cout << q.front().second << endl;
    
    return 0;
}
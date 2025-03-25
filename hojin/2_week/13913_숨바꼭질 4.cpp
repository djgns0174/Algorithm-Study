#include <iostream>
#include <queue>
using namespace std;

struct node{ 
    int val; 
    int lev; 
};

int main() {
    int N, K;
    queue<node> q;
    int visited[100001]; // 이전 경로 저장
    fill(visited, visited+100001, -1);
    cin >> N >> K;
    
    node n;
    n.val = N;
    n.lev = 0;
    q.push(n);
    visited[N] = -2;
    node cur = n;
    
    while (!q.empty()){
        cur = q.front();
        if (cur.val == K) break;
        q.pop();
        
        if ((cur.val>0) && (visited[cur.val-1] == -1)) {
            visited[cur.val-1] = cur.val;
            n.val = cur.val-1;
            n.lev = cur.lev+1;
            q.push(n);
        }

        if ((cur.val<100000) && (visited[cur.val+1] == -1)){
            visited[cur.val+1] = cur.val;
            n.val = cur.val+1;
            n.lev = cur.lev+1;
            q.push(n);
        }

        if ((cur.val<=50000) && (visited[2*cur.val] == -1)){
            visited[2*cur.val] = cur.val;
            n.val = 2*cur.val;
            n.lev = cur.lev+1;
            q.push(n);
        }

    }
    
    cout << cur.lev << endl;
    
    vector<int> way(cur.lev+1); // 역순으로 출력
    
    int i = 0;
    way[i] = cur.val;
    while (visited[cur.val] != -2){
        cur.val = visited[cur.val];
        way[++i] = cur.val;
    }
    for (int i=way.size()-1; i>=0; i--){
        cout << way[i] << " ";
    }
    return 0;
}
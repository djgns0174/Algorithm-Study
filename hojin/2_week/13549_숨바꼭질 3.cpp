#include <iostream>
#include <queue>
using namespace std;

struct node{ 
    int val; 
    int lev; 
};

int main() {
    int N, K, answer = 0;
    queue<node> q;
    bool visited[100001] = {false};
    cin >> N >> K;
    
    node n;
    n.val = N;
    n.lev = 0;
    q.push(n);
    visited[N] = true;
    node cur = n;
    
    while (!q.empty()){
        cur = q.front();
        if (cur.val == K) break;
        q.pop();
        
        if ((cur.val<=50000) && !visited[2*cur.val]){
            visited[2*cur.val] = true;
            n.val = 2*cur.val;
            n.lev = cur.lev;
            q.push(n);
        }
        
        if ((cur.val>0) && !visited[cur.val-1]) {
            visited[cur.val-1] = true;
            n.val = cur.val-1;
            n.lev = cur.lev+1;
            q.push(n);
        }

        if ((cur.val<100000) && !visited[cur.val+1]){
            visited[cur.val+1] = true;
            n.val = cur.val+1;
            n.lev = cur.lev+1;
            q.push(n);
        }

       
    }
    
    cout << cur.lev;
    return 0;
}
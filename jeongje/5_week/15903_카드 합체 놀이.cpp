#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

static int arr[1001];

int main(){
    int N, M;
    cin >> N >> M;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq; // 우선순위 큐(오름차순으로)
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    
    for(int i=0;i<M;i++)
    {
        ll first = pq.top(); pq.pop(); // 가장 작은 수 꺼내기
        ll second = pq.top(); pq.pop(); // 두 번째로 작은 수 꺼내기
        
        // 두 카드 합쳐서 큐에 다시 넣기
        pq.push(first + second);
        pq.push(first + second);
    }
    
    ll sum = 0;
    while(!pq.empty()){
        ll now = pq.top(); pq.pop();
        sum += now;
    }
    
    cout << sum;
}
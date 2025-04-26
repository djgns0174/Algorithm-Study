#include<iostream>
#include<algorithm>
#include<queue>
#define endl "\n"

using namespace std;

/*
    휴게소 세우기 - 1477 - 미해결

    [이분 탐색]
    1. 인접한 휴게소 간의 거리를 구하고 배열에 넣는다.
    2. 가장 큰 거리를 선택해서 휴게소를 하나 세운다.
        1. 거리가 홀수면 (거리/2+1)을 배열에 추가 
        2. 짝수면 (거리/2)를 배열에 추가
    3. 다음 가장 큰 거리를 선택해서 휴게소를 하나 세운다.
        1. 이미 휴게소를 하나 세운 거리라면 원래 거리에서 +1으로 나눈값 배열에 추가 
            1. 나누어 떨어지지 않으면 몫+1 을 배열에 추가한다.
            2. 나누어 떨어지면 몫을 배열에 추가한다.
        2. 그렇지 않다면 그냥 2로 나누어서 배열에 추가

    [정답 여부]
    5% 에서 틀림

    [해결방법]
    2차원 배열 대신 우선순위 큐를 사용하면 맞는다. 
    왜그런지는 모르겠음 ㅜㅜ

    [시간복잡도]
    Nlogn(처음 입력 배열값 정렬) + mlogn(우선순위 큐를 사용한 그리디)
*/

int main(void){

    int n, m, l;
    cin >> n >> m >> l;

    if(n == 0){
        int count = m+1;
        if(l % count == 0) cout << l/count << endl;
        else cout << (l/count) + 1 << endl;
        return 0;
    }

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    // 우선순위 큐 사용
    priority_queue<pair<int, pair<int,int>> > pq;
    for(int i=0; i<n; i++)
    {
        if(i==0) pq.push({arr[i], {arr[i], 1}});
        else pq.push({arr[i] - arr[i-1], {arr[i] - arr[i-1], 1}});
    }
    pq.push({l-arr[n-1], {l-arr[n-1], 1}});

    for(int i=0; i<m; i++){
        auto top = pq.top(); pq.pop();
        int count = top.second.second + 1;

        int nextGap;
        if(top.second.first % count == 0) nextGap = top.second.first / count;
        else nextGap = (top.second.first / count) + 1;

        pq.push({nextGap, {top.second.first, count}});
    }

    cout << pq.top().first << endl;

    /*
    // 2차원 벡터 사용 후 정렬 -> 틀리는데 이유 모르겠음;;
    vector<vector<int> > dist(n+1);
    for(int i=0; i<n+1; i++){
        if(i == 0) dist[i] = {arr[i], arr[i], 1};
        else dist[i] = {arr[i] - arr[i-1], arr[i] - arr[i-1] , 1};
    }
    dist[n] = {l - arr[n-1], l - arr[n-1], 1};

    sort(dist.begin(), dist.end());

    for(int i=0; i<m; i++){
        int count = ++dist.back()[2];

        if(dist[n][0] % count == 0)
            dist[n][0] = dist[n][1] / count;
        else 
            dist[n][0] = (dist[n][1] / count) + 1;
        
        sort(dist.begin(), dist.end());
    }

    cout << dist.back()[0] << endl;
    */
    
    return 0;
}
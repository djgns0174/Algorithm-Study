#include<iostream>
#define endl "\n"

using namespace std;

/*
    [DP vs Greedy]
    이 문제는 동전 개수의 최솟값을 구하는 문제로써 가장 큰 가치의 동전부터 차례대로
    줄여 나가는 것이 효율적이여 보인다. 모든 경우의 수를 구할 필요가 없어보인다.
    Greedy가 DP보다 효율적이여 보인다. 

    [코드 설명]
    가장 큰 가치의 동전부터 나누어서 몫은 answer에 더해주고 나머지는 다시 다음 
    큰 가치의 동전으로 처리
*/

int main(void){
    int n, k;
    cin >> n >> k;

    int coin[10];
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    int answer = 0;
    for(int i=n-1; i>=0; i--){
        if(k<coin[i]) continue;
        answer += k / coin[i];
        k = k % coin[i];
        if(k == 0) break;
    }

    cout << answer << endl;
    
    return 0;
}
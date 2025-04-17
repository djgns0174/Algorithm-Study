#include<iostream>
#define endl "\n"
#define max_int 1000000001
using namespace std;

/*
    [분할정복] n^2
    1. 제일 싼곳을 찾고 거기부터 남은 거리 주유
    2. 이 과정을 첫번째 도시에 도달할 때 까지 반복한다.

    [틀린 이유]
    최악의 경우 10만의 제곱인 100억 연산을 수행해야되므로 시간초과가 나옴
    해결책 : 시간복잡도 n^2 을 n 으로 수정해야됨.
*/

int n;
int answer = 0;
int dist[100001] = {0,};
int price[100001] = {0,};
int minIndex, minPrice;

void input(){
    for(int i=1; i<=n-1; i++){
        cin >> dist[i];
    }

    for(int i=1; i<=n; i++){
        cin >> price[i];
    }
}

void greedy(int range){
    minPrice = max_int;
    for(int i=range; i>=1; i--){
        if(minPrice > price[i]){
            minIndex = i;
            minPrice = price[i];
        }
    }

    int sumDistance = 0;
    for(int i=minIndex; i<=range; i++){
        sumDistance += dist[i];
    }

    answer += sumDistance * minPrice;
}

int main(void){

    cin >> n;

    input();
    
    minIndex = 1;
    greedy(n-1);

    while(1){
        if(minIndex == 1) break;
        greedy(minIndex - 1);
    }

    cout << answer << endl;
        
    return 0;
}
#include<iostream>
#define endl "\n"

using namespace std;

/*
    [그리디] n
    1. 첫번째는 무조건 주유
    2. 두번째부터 이전 리터가격보다 비싸면 이전 주유, 싸면 현재 주유
    3. 도착할때까지 반복

    [틀린 이유]
    int형 자료형을 사용하여 최댓값 1,000,000,000이 들어올때 오버플로우 발생함.
*/

long dist[100001] = {0,};
long price[100001] = {0,};

int main(void){

    int n;
    cin >> n;

    for(int i=1; i<=n-1; i++){
        cin >> dist[i];
    }

    for(int i=1; i<=n; i++){
        cin >> price[i];
    }

    long answer = 0;
    long minPrice = price[1];
    answer = dist[1] * price[1];
    for(int i=2; i<=n-1; i++){
        if(minPrice > price[i]){
            answer += dist[i] * price[i];
            minPrice = price[i];
        }
        else {
            answer += dist[i] * minPrice;
        }
    }

    cout << answer << endl;
    
    return 0;
}
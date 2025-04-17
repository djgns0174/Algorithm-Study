#include<iostream>
#define endl "\n"
#define max_value 9223372036854775807
using namespace std;

/*
    [그리디]
    가장 작은 카드 두개를 합침
    그것을 m번 반복
    카드 전부 더함

    [오버플로우 분석]
    최대 자연수 : 100만
    최대 카드의 개수 : 1000
    최대 카드 합체 : 15000

    100만 x 15000 = 150억으로 long자료형 사용하는게 안전

    [시간복잡도 분석]
    가장 작은 카드를 찾는 로직 = n^2
    최대 카드의 개수가 1000이므로 1000000으로 시간초과 안남

    [틀린 이유]
    max_value를 100만으로 설정하였는데 연산하면서 최대 150억까지 카드 숫자가 커질 수 있음
    해결방법 : 100만 -> long 최대숫자
*/

long card[1001];

int main(void){

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> card[i];
    }

    for(int i=1; i<=m; i++){
        long minCard1 = max_value;
        long minCard2 = max_value;
        int minCard1Index = 0;
        int minCard2Index = 0;

        for(int j=1; j<=n; j++){
            if(card[j] < minCard1){
                minCard1 = card[j];
                minCard1Index = j;
            }
        }
        for(int j=1; j<=n; j++){
            if(j == minCard1Index) continue;
            if(card[j] < minCard2){
                minCard2 = card[j];
                minCard2Index = j;
            }
        }
        card[minCard1Index] = minCard1 + minCard2;
        card[minCard2Index] = minCard1 + minCard2;
    }



    long answer = 0;
    for(int i=1; i<=n; i++){
        answer += card[i];
    }
    cout << answer << endl;
    
    return 0;
}
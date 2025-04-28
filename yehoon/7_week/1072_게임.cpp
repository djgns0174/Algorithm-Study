#include<iostream>

#define endl "\n"

using namespace std;

/*
    게임 - 1072

    [그리디]
    1. 이긴게임 / 게임횟수 = 승률
    2. 이긴게임과 게임횟수 증가시켜서 승률이 변화될때까지 반복한다.

    [시간복잡도]
    최악의 경우 (10억 0)
    -> 1000만번 게임하면 승률이 오름

    [틀린 이유]
    부동소수점 오류가 있다.
    (y/x) * 100 -> 나누기를 먼저 수행하면 소수점 미세한 오차때문에 오류발생 가능성 높아짐
    (y*100) / x -> 나누기를 나중에 수행하면 오류 발생 가능성이 낮아진다.
*/

int main(void){

    double x, y;
    cin >> x >> y;

    int winRate = (y * 100) / x;

    if(winRate == 100 || winRate == 99) cout << -1 << endl;
    else {
        int answer = 0;
        while(1)
        {
            answer++;
            x++; y++;
            int change = (y * 100)/ x;
            if(change != winRate)
                break;
        }

        cout << answer << endl;
    }
    
    return 0;
}
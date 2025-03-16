#include <iostream>

using namespace std;

bool isHansu(int a);

int main()
{
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(isHansu(i)){
            cnt++;
        }
    }
    
    cout << cnt;
}

bool isHansu(int a) {
    if(a < 100) return true; // 두 자리수 이하는 무조건 한수
    if(a == 1000) return false; // 최대값 1000은 한수 X
    
    int a1, a2, a3;
    a1 = a / 100; // 3의 자리수
    a2 = a % 100 / 10;  // 2의 자리수
    a3 = a % 10; // 1의 자리수
    
    if(a1 - a2 == a2 - a3) {
        return true;
    }
    return false;
}
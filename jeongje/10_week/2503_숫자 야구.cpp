#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

static int N;
static vector<tuple<int, int, int>> v;

static bool isValid(int number);

int main(){
    cin >> N;

    for(int i=0;i<N;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        v.push_back({a, b, c});
    }
    
    // 9 * 8 * 7 = 504개의 경우의 수를 모두 확인하기
    int count = 0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i==j) continue;
            for(int k=1;k<=9;k++){
                if(i == k || j == k) continue;
                int number = (i * 100) + (j * 10) + k;
                
                
                if(isValid(number)) count++;
            }
        }
    }
    
    
    cout << count;
}

bool isValid(int number) {
    int numberArr[3];
    
    numberArr[0] = number % 10; // number의 일의 자리수 
    numberArr[1] = (number % 100) / 10; // number의 십의 자리수
    numberArr[2] = number / 100; // number의 백의 자리수
    
    for(int i=0;i<N;i++){
        auto [target, strike, ball] = v[i];
        
        int targetArr[3];
        
        targetArr[0] = target % 10; // target의 일의 자리수 
        targetArr[1] = (target % 100) / 10; // target의 십의 자리수
        targetArr[2] = target / 100; // target의 백의 자리수
        
        int strikeCheck = 0;
        int ballCheck = 0;
        
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(numberArr[j] == targetArr[k]) { // 숫자를 맞춘 경우 
                    if(j==k) { // 자리 수까지 맞춰서 스트라이크
                        strikeCheck++;
                        continue;
                    }
                    ballCheck++; // 자리수는 다르면 볼 
                }
            }
        }
        
        // 스트라이크 수와 볼의 수가 정답과 다르면 해당 number는 경우의 수 탈락 
        if((strike != strikeCheck) || (ball != ballCheck)) return false;
        
    }
    
    return true;
}
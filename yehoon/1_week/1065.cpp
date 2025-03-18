#include<iostream>
#include<string>
using namespace std;
int main(void){
    int n;
    cin >> n;

    // 1,2자리수 처리
    if(n < 100){
        cout << n << endl;
        return 0;
    }

    int answer = 99;
    //3자리수 처리
    for(int i=100; i<=n; i++){
        string str = to_string(i);
        int tmp1 = (str[0] - '0');
        int tmp2 = (str[1] - '0');
        int tmp3 = (str[2] - '0');

        int diff1 = tmp1 - tmp2;
        int diff2 = tmp2 - tmp3;
        if(diff1 == diff2){
            answer++;
        }
    }

    cout << answer << endl;
}
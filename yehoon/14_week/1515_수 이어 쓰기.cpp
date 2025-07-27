#include<iostream>
#include<string>
#define endl "\n"
using namespace std;

/*
수 이어 쓰기 - 1515

[그리디]
반복문으로 1부터 증가시킨다.
해당 값의 자리수를 추출한다.
자리수와 이어붙인 수와 맞는지 확인한다.
맞으면 이어붙인 수에서 해당 숫자를 없앤다.
이어붙인 수가 없어질 때까지 진행한다.
*/

int main(void)
{
    int answer = 1;
    string input; cin >> input;

    while(input.length() != 0)
    {
        string s = to_string(answer);
        for(char c : s)
        {
            if(input[0] == c) input.erase(0,1);
        }
        answer++;
    }

    cout << answer - 1 << endl;
    
    return 0;
}
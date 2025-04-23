#include<iostream>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    기타 레슨

    [이분탐색] 
    Start = 가장 긴 강의 길이
    End = 전체 강의 길이의 합

    이분탐색을 하여서 블루레이 크기를 먼저 선택한다.
    선택된 블루레이 크기에 해당하는 블루레이 개수를 구한다.

    1. 블루레이 개수가 m 초과이다. -> 블루레이 크기를 더 작게 해야된다. -> end = key-1 
    2. 블루레이 개수가 m보다 작다. -> 블루레이 크기를 더 크게 해야된다. -> start = key+1

    이런식으로 반복해서 블루레이 개수가 m이 나올때까지 진행하고 나왔으면 
    블루레이 크기가 가장 큰 것을 정답으로 내면 된다.

    [틀린 이유]
    블루레이 개수가 m이 나오고 반복문을 나오게 되면 정답을 도출해 낼 수 없다.
    블루레이의 크기가 더 작은값이 존재할 수 있기 때문이다.

    [해결 방안]
    블루레이 개수가 m이 나와도 계속해서 이분탐색을 수행한다.
    이분탐색을 수행할수록 정답에 수렴하게 되고 마지막 내려가는 경우(count<=m)에 정답을 저장하면 블루레이의 크기(적은 값들 중 가장 큰 값 선택)는 모두 같을 수 있게 된다.

    [시간복잡도]
    Log2(10억)(블루레이 크기 선택) * 10만(블루레이 개수 선택) = 약 30만

*/

int main(void){

    int n, m;
    cin >> n >> m;

    int start = 0;
    int end = 0;

    vector<int> lecture;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        lecture.push_back(input);

        start = max(start, input);
        end += input;
    }

    int key;
    int answer;
    while(start <= end){
        key = (start + end) / 2;

        int count = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += lecture[i];

            if(key < sum){
                count++;
                sum = lecture[i];
            }
        }

        if(count <= m){
            end = key - 1;
            answer = key;
        }
        else 
            start = key + 1;
    }
    
    cout << answer << endl;
    
    return 0;
}
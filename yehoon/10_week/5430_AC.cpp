#include<iostream>
#include<vector>
#include<sstream>

#define endl "\n"

using namespace std;

/*
    [구현]
    1. 배열의 앞과 뒤를 나타내는 Front 와 Tail 변수를 둔다.
    2. R이 수행되면 curr 변수는 Front -> Tail 또는 Tail -> Front 로 바뀐다.
    3. D가 수행되면 curr 변수에서 
        1. Front 이면 +1
        2. Tail 이면 -1
    4. Front 부터 Tail 까지 출력한다. 
        1. 만약 Front > Tail 이면 Error 출력

    [시간복잡도]
    최악의 경우 T는 100이고 p의 길이가 10만일때 100 x 10만 = 1000만으로 통과
*/

int main(void)
{
    int t; cin >> t;

    for(int i=0; i<t; i++)
    {
        string p; cin >> p;
        int n; cin >> n;
        string inputArr; cin >> inputArr;

        // 배열 세팅
        inputArr = inputArr.substr(1, inputArr.size()-2);
        stringstream ss(inputArr);
        string token;
        vector<int>arr;
        while(getline(ss, token, ',')) arr.push_back(stoi(token));

        // front, tail 값 조정
        int front = 0; int tail = arr.size();
        int *curr = &front;

        for(int j=0; j<p.size(); j++)
        {
            if(p[j] == 'R')
            {
                if(curr == &front) curr = &tail;
                else curr = &front;
            }
            else 
            {
                if(curr == &front) front++;
                else tail--;
            }
        }

        // 정답 출력
        if(front > tail) cout << "error" << endl;
        else
        {
            cout << "[";
            
            // 현재 값에 따라 front부터 출력할지 tail부터 출력할지 분기
            if(curr == &front)
            {
                for(int j=front; j<tail; j++)
                {   
                    if(j==tail-1) cout << arr[j];
                    else cout << arr[j] << ",";
                }
            }
            else 
            {
                for(int j=tail-1; j>=front; j--)
                {   
                    if(j==front) cout << arr[j];
                    else cout << arr[j] << ",";
                }
            }
            cout << "]" << endl;;
        }
    }
    
    return 0;
}
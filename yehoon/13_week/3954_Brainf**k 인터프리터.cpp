#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<sstream>
#include<string>
#include<algorithm>
#include<climits>
#define endl "\n"
#define MAX_EXEC_CNT 50000000
using namespace std;

/*
Brainf**k 인터프리터 - 3954

명령어를 5000만번 수행했을 때 프로그램이 끝나지 않는다면 무한루프에 빠져있다고 문제에서 간주한다. 5000만번을 수행한 후 무한루프 속으로 들어가서 5000만번 더 수행하여 해당 루프의 범위를 탐색하면 된다.(무한루프 안에 유한루프가 있을 수 있음) 최대 범위를 변수에 저장해 두어서 해당 위치의 짝 루프 위치를 출력해주면 된다.
*/

int main(void)
{
    int t; cin >> t;
    
    vector<string> answers;
    for(int i=0; i<t; i++)
    {
        // 입력 받기
        int s_m, s_c, s_i; cin >> s_m >> s_c >> s_i;
        string command; cin >> command;
        string input; cin >> input;
        int input_pointer = 0;

        // 메모리 초기화
        vector<int>arr(s_m, 0);
        int pointer = 0;

        // 중첩문 스택
        stack<int> stack;

        unordered_map<int,int> loop_couple;  // 중첩문 짝 위치 저장
        unordered_map<int,int> loop_reverse_couple;  // 중첩문 짝 위치 저장
        for(int j=0; j<s_c; j++)
        {
            if(command[j] == '[')
            {
                stack.push(j);
            }

            else if(command[j] == ']')
            {
                loop_couple[stack.top()] = j;
                loop_reverse_couple[j] = stack.top();
                stack.pop();
            }
        }

        int exec_cnt = 0;
        int j = 0;
        int minj = INT_MAX;
        int maxj = INT_MIN;
        for(; j<s_c; j++)
        {
            exec_cnt++;

            char c = command[j];
            if(exec_cnt >= MAX_EXEC_CNT * 2)
            {
                ostringstream oss;
                oss << "Loops " << loop_reverse_couple[maxj] << " " << maxj;
                answers.push_back(oss.str());
                break;
            }

            if(exec_cnt > MAX_EXEC_CNT)
            {
                maxj = max(maxj, j);
                minj = min(minj, j);
            }

            switch (c)
            {
            case '+':
                arr[pointer] = (arr[pointer] + 1) % 256; // 오버플로우 처리
                break;

            case '-':
                arr[pointer]--;
                if(arr[pointer] < 0) arr[pointer] = 255; // 언더플로우 처리
                break;

            case '>':
                pointer = (pointer + 1) % s_m;
                break;
            
            case '<':
                pointer--;
                if(pointer < 0) pointer = s_m - 1;
                break;

            case '[':
                if(arr[pointer] == 0) // 포인터가 가르키는 수가 0이라면 
                {
                    j = loop_couple[j] - 1;
                }
                break;

            case ']':
                if(arr[pointer] != 0) // 포인터가 가르키는 수가 0이 아니라면 (반복문이 종료되지 않는다면)
                {
                    j = loop_reverse_couple[j] - 1;
                }
                break;

            case '.':
                // 문제조건에 출력은 무시
                break;
            
            case ',':
                if(input_pointer >= input.size()) arr[pointer] = 255;
                else arr[pointer] = (int) input[input_pointer];
                input_pointer++;
                break;
            }
        }

        if(exec_cnt < MAX_EXEC_CNT * 2) answers.push_back("Terminates"); // 정상 종료
    }

    for(string answer : answers) cout << answer << endl;
    
    
    return 0;
}
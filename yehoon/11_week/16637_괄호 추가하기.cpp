#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>

#define endl "\n"

using namespace std;

/*
    [완전탐색 + DFS(조합)]
    피연산자 괄호로 묶기 : 
    피연산자 / 2 = 최대 괄호의 개수

    For 0 ~ 최대 괄호의 개수 

    괄호의 개수만큼 피연산자를 괄호로 묶는다.

    피연산자에서 괄호의 개수만큼 조합으로 뽑는다. 
        - 연속된 피연산자를 뽑으면 안됨
        - 맨 마지막 피연산자를 뽑으면 안됨

    괄호 안에는 뽑힌 피연산자와 바로 오른쪽 피연산자를 취급한다. 

    연산하기 : 
        괄호 안에 피연산자들을 연산자와 연산하고 결과를 벡터에 추가한다. 
        괄호로 묶이지 않은 피연산자는 바로 벡터에 추가한다.

        괄호를 연산하는데 사용된 연산자는 제거한다. 

        남는 피연산자와 연산자를 사용해서 나머지 결과를 answers 벡터에 저장한다. 

    [시간복잡도]
    최악의 경우 n이 19 들어올때 피연산자의 개수는 10

    9C0 + … + 9C9 = 512
    512(괄호로 묶기) * {90(괄호 연산 수행) + 9 + 19 + 19} = 약 10만으로 통과
*/

// 피연산자가 괄호로 묶이는지
vector<bool>selected;
vector<int> selected_op_idx;

vector<vector<int>> combination;

vector<int> answers;

vector<int> operands;
vector<char> operators;

int calculate(int operand1_arg, char operator_arg, int operand2_arg)
{
    if(operator_arg == '+') return operand1_arg + operand2_arg;

    else if(operator_arg == '-') return operand1_arg - operand2_arg;

    else if(operator_arg == '*') return operand1_arg * operand2_arg;
    
    else
    {
        cout << "[ERROR] 허용되지 않은 연산자:" << operator_arg << endl;
        return -1;
    }
}

void comb(int start, int depth, int max_pa)
{
    if(depth == max_pa)
    {
        vector<char> local_operators = operators;
        vector<int>final_operands;
        // 괄호 연산 수행
        for(int i=0; i<operands.size(); i++)
        {
            // 괄호로 묶였다면
            if(find(selected_op_idx.begin(), selected_op_idx.end(), i) != selected_op_idx.end())
            {
                int operand1_arg = operands[i];
                int operand2_arg = operands[i+1];
                char operator1_arg = operators[i];
                // cout << "[INFO] "<< operator1_arg << " 을 ' ' 으로 바꿉니다." << endl;
                local_operators[i] = ' ';
                
                // 연산하기
                int final_operand = calculate(operand1_arg, operator1_arg, operand2_arg);
                final_operands.push_back(final_operand);
                
                i += 1;
            }

            // 묶이지 않았으면 중간 결과값 바로 저장
            else 
            {
                final_operands.push_back(operands[i]);
            }
        }

        vector<char> final_operators;
        // 연산자 세팅
        for(char op : local_operators)
        {
            if(op == ' ') continue;
            else final_operators.push_back(op);
        }  

        // 최종 연산 수행
        queue<string> q;
        q.push(to_string(final_operands[0]));

        for (int i = 0; i < final_operators.size(); i++) {
            q.push(string(1, final_operators[i]));
            q.push(to_string(final_operands[i + 1]));
        }

        int answer = stoi(q.front()); q.pop();
        while(!q.empty())
        {
            char operator_arg = q.front()[0]; q.pop();
            int operand_arg2 = stoi(q.front()); q.pop();

            answer = calculate(answer, operator_arg, operand_arg2);
        }

        answers.push_back(answer);
    }

    else 
    {
        for(int i=start; i<operands.size()-1; i++)
        {
            // 연속된 피연산자를 뽑으면 안됨
            if(i>0 && selected[i-1]) continue;

            selected_op_idx.push_back(i);
            selected[i] = true;

            comb(i+1, depth+1, max_pa);

            selected_op_idx.pop_back();
            selected[i] = false;
        }
    }
}

int main(void)
{
    int n; cin >> n;

    string input; cin >> input;

    if(n == 1)
    {
        cout << input << endl;
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        if(i%2 == 0) operands.push_back((int)input[i] - '0');
        else operators.push_back(input[i]);
    }

    // 최대 괄호의 개수
    int max_pa = operands.size() / 2;

    for(int i=0; i<=max_pa; i++)
    {
        selected = vector<bool>(operands.size(), false);

        // 괄호 묶기
        comb(0, 0, i);
    }

    int answer = INT_MIN;
    for(int value : answers) answer = max(answer, value);

    cout << answer << endl;

    return 0;
}
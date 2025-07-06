#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

char arr[20];
bool check[20];

int N, answer = INT_MIN;

void dfs(int max_gwalho_count, int count);
void calculate();
int compute(int a, int b, char op);

int main(){
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    // arr 배열에서 홀수 인덱스는 숫자 
    // 짝수 인덱스는 연산자가 위치함
    int max_gwalho_count = N / 2;
    
    for(int i=0;i<=max_gwalho_count;i++)
    {
        dfs(i, 0);
    }
    
    
    cout << answer;
}

void dfs(int max_gwalho_count, int count)
{
    if(max_gwalho_count == count) {
        calculate();
        return;
    }
    
    // 인덱스 짝수 자리는 연산자 자리 
    for(int i=2;i<N;i+=2){
        if(check[i] == false && check[i-1] == false && check[i+1] == false)
        {
            check[i - 1] = check[i] = check[i + 1] = true;
            
            dfs(max_gwalho_count, count + 1);
            
            check[i - 1] = check[i] = check[i + 1] = false;
        }
    }
}

int compute(int a, int b, char op)
{
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

void calculate()
{
    vector<int> num;
    vector<char> op;
    
    for(int i=1;i<=N;i++){
        if(i % 2 == 1){ // 홀수 인덱스 (숫자가 위치하는 곳)
            if(i + 1 <= N && check[i] && check[i+1] && check[i+2]) { // 유효 범위 안이면서 괄호로 묶인 곳 
                int a = arr[i] - '0';
                int b = arr[i+2] - '0';
                char o = arr[i+1];
                
                num.push_back(compute(a, b, o));
                
                i += 2;
            } else {
                num.push_back(arr[i] - '0');
            }
        } else { // 짝수 인덱스 (연산자가 위치하는 곳)
            if(!check[i]) op.push_back(arr[i]);
        }
    }
    
    int result = num[0];
    
    for(int i=0;i<op.size();i++){
        result = compute(result, num[i+1], op[i]);
    }
    
    answer = max(answer, result);
}
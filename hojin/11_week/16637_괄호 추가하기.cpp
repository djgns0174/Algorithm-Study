#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl "\n"

int calc(int first, char oper, int second){
    int result;
    if (oper == '+') result = first + second;
    if (oper == '-') result = first - second;
    if (oper == '*') result = first * second; 

    return result;
}

int result = -2147483648;
int operSize;
vector<int> terms; // 항 벡터
vector<char> opers; // 연산자 벡터


void doOper(int preCal, int curOperIdx){
    // 모든 항 계산 완료 (현재 인덱스 > 연산자 인덱스)
    if (curOperIdx >= operSize){ 
        result = max(preCal, result);
        return;
    }
    else {
        // 괄호 OX 분기를 위해 preCal 복사
        int branchPreCal = preCal;
        // 괄호 O
        if (curOperIdx+1 <= operSize-1){
            int tmp = calc(terms[curOperIdx+1], opers[curOperIdx+1], terms[curOperIdx+2]);
            preCal = calc(preCal, opers[curOperIdx], tmp);
            doOper(preCal, curOperIdx+2);
        }
        // 괄호 X
        branchPreCal = calc(branchPreCal, opers[curOperIdx], terms[curOperIdx+1]);
        doOper(branchPreCal, curOperIdx+1);
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    terms.resize(((n-1)/2)+1);
    operSize = (n-1)/2;
    opers.resize(operSize);
    

    for (int i=0; i<terms.size(); i++){
        terms[i] = s[2*i] - '0';
    }
    for (int i=0; i<opers.size(); i++){
        opers[i] = s[2*i + 1];
    }

    int preCal = terms[0];
    
    doOper(preCal, 0);
    
    cout << result;

    return 0;
}
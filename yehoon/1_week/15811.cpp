#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isBokMyunSan = false;
string str1, str2, str3;
bool isUsedAlphabet[26] = {false};
bool isUsedNumber[10] = {false};
int numOfAlphabet[26] = {-1};
vector <int> alphabet;

void init(){
    for(int i=0; i<str1.size(); i++){
        int alphabetIndex = str1[i] - 'A';
        isUsedAlphabet[alphabetIndex] = true;
    }
    for(int i=0; i<str2.size(); i++){
        int alphabetIndex = str2[i] - 'A';
        isUsedAlphabet[alphabetIndex] = true;
    }
        for(int i=0; i<str3.size(); i++){
        int alphabetIndex = str3[i] - 'A';
        isUsedAlphabet[alphabetIndex] = true;
    }
}

void checkBokMyunSan(){
    int result1 = 0;
    for(int i=0; i<str1.size(); i++){
        result1 = result1 * 10 + numOfAlphabet[str1[i] - 'A'];
    }

    int result2 = 0;
    for(int i=0; i<str2.size(); i++){
        result2 = result2 * 10 + numOfAlphabet[str2[i] - 'A'];
    }

    int result3 = 0;
    for(int i=0; i<str3.size(); i++){
        result3 = result3 * 10 + numOfAlphabet[str3[i] - 'A'];
    }

    if(result1 + result2 == result3) isBokMyunSan = true;
}

void dfs(int level){
    if(isBokMyunSan) return;

    if(level == alphabet.size()){
        checkBokMyunSan();
    } else {
        for(int i=0; i<10; i++){
            if(isUsedNumber[i]) continue;
            isUsedNumber[i] = true; 
            numOfAlphabet[alphabet[level]] = i;
            dfs(level+1);
            isUsedNumber[i] = false;
        }
    }
}

int main(void){

    cin >> str1 >> str2 >> str3;

    init();

    for(int i=0; i<26; i++){
        if(isUsedAlphabet[i]){
            alphabet.push_back(i);
        }
    }

    dfs(0);
        
    if(isBokMyunSan) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
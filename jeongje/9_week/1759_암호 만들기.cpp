#include <iostream>
#include <algorithm>

using namespace std ;

static int L, C ;
static char arr[15];
static char password[15];

void DFS(int start, int cnt);
bool isValid(char* password);

int main() {
    cin >> L >> C ;
   
    for(int i=0;i<C;i++){
        cin >> arr[i];
    }
   
    sort(arr, arr + C); // 사전 순으로 정렬
   
    DFS(0, 0);
   
    return 0;
}


void DFS(int start, int cnt) {
    if(cnt == L) {
        if(isValid(password)) { // 최소 한 개의 모음 && 최소 두 개의 자음 인지 체크
            for(int i=0;i<L;i++){
                cout << password[i];
            }
            cout << "\n";
        }
        return;
    }
   
    // 암호 조합 만드는 DFS
    for(int i = start; i < C; i++){
        password[cnt] = arr[i];
        DFS(i + 1, cnt + 1);
    }
}

bool isValid(char* password) {
    int moEumCount = 0;
    int jaEumCount = 0;
   
    for(int i=0;i<L;i++){
        if (password[i] == 'a' || password[i] == 'e' ||
            password[i] == 'i' || password[i] == 'o' ||
            password[i] == 'u') {
               moEumCount++;
            }
        else {
            jaEumCount++;
        }
    }
   
   
    if((moEumCount >= 1) && (jaEumCount >= 2)) return true;
    else return false;
}
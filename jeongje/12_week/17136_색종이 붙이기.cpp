#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int arr[10][10];

int paper[6] = {0, 5, 5, 5, 5, 5};

int ans = INT_MAX;

bool canAttach(int x, int y, int size);
void dfs(int cnt);
void attach(int x, int y, int size, int val);

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> arr[i][j];
        }
    }
    
    dfs(0);
    
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}


void dfs(int cnt){
    int x = -1, y = -1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j] == 1) {
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    
    if(x==-1){ // 다 붙인 경우 
        ans = min(ans, cnt);
        return;
    }
    
    for(int size=5; size>=1;size--){
        if(paper[size] > 0 && canAttach(x, y, size)) {
            attach(x, y, size, 0);
            paper[size]--;
            
            dfs(cnt + 1);
            
            attach(x, y, size, 1);
            paper[size]++;
        }
    }
}

void attach(int x, int y, int size, int val){
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            arr[i][j] = val;
        }
    }
}


bool canAttach(int x, int y, int size)
{
    if(x+size > 10 || y+size > 10) return false;
    
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(arr[i][j] == 0) return false;
        }
    }
    
    return true;
}
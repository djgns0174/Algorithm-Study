#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N+1);
    
    for(int i=1;i<=N;i++){
        cin >> v[i];
    }
    
    int count = 0;
    int i = N;
    while(K){
        if(v[i] > K) {
            i--;
            continue;
        }

        count += K / v[i];
        K %= v[i];
    }
    
    
    cout << count;
}
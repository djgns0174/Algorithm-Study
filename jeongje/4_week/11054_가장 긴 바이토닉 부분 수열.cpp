#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> v(N+1);
    vector<int> up(N+1, 1);
    vector<int> down(N+1, 0);
    
    vector<int> sum(N+1);
    
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            if(v[i] > v[j]) {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }
    
    for(int i=N; i>=1; i--){
        for(int j=i+1; j<=N; j++){
            if(v[i] > v[j]) {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }

    for(int i=1;i<=N;i++){
        sum[i] = up[i] + down[i];
    }
    
    int max = 0;
    
    for(int i=1;i<=N;i++){
        if(max < sum[i]) max = sum[i];
    }
    
    cout << max;
    
    return 0;
}

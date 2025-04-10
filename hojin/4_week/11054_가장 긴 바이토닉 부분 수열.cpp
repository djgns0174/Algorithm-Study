
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, maxlen = 0;
    int p;
    cin >> N;
    int arr[N+1];
    int dpinc[N+1];
    int dpdec[N+1];
    for (int i=1; i<N+1; i++){
        cin >> arr[i];
        dpinc[i] = 1;
        dpdec[i] = 1;
    }
    
    for (int i=1; i<N+1; i++){
        for (int j=1; j<i; j++){
            if (arr[j] < arr[i]){
                dpinc[i] = max(dpinc[i], dpinc[j]+1);
            }
        }
    }
    
    for (int i=N; i>=1; i--){
        for (int j=i+1; j<=N; j++){
            if (arr[j] < arr[i]){
                dpdec[i] = max(dpdec[i], dpdec[j]+1);
            }
        }
    }
    
    for (int i=1; i<=N; i++){
        maxlen = max(maxlen, dpinc[i]+dpdec[i]-1);
    }
    cout << maxlen;
    
    return 0;
}
#include <iostream>
#include <vector> 

using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    
    vector<ll> mdistance(N-1);
    vector<ll> price(N);
    
    for(int i=0;i<N-1;i++){
        cin >> mdistance[i];
    }
    
    for(int i=0;i<N;i++){
        cin >> price[i];
    }
    
    ll result = 0;
    ll min_price = price[0];
    
    for(int i=0;i<N-1;i++){
        if(i==0){
            result = mdistance[0] * price[0];
        } else {
            if(price[i] < min_price) {
                min_price = price[i];
            }
            result += mdistance[i] * min_price;
        }
    }
    
    cout << result;
}
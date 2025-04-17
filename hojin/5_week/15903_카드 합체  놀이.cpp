#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    long long card[1001];
    for (int i=0; i<n; i++){
        cin >> card[i];
    }
    
    int min1index;
    int min2index;
    for (int i=0; i<m; i++){
        long long min1 = 9223372036854775807;
        long long min2 = 9223372036854775807;
        for (int j=0; j<n; j++){
            if (min1 > card[j]){
                min1 = card[j];
                min1index = j;
                // cout << "min1index: " << min1index << '\n';
            }
        }
        for (int k=0; k<n; k++){
            if (min2 > card[k] && k != min1index){
                min2 = card[k];
                min2index = k;
                // cout  << "min2index: " << min2index << '\n';
            }
        }
        card[min1index] = min1 + min2;
        card[min2index] = min1 + min2;
    }
    long long sum = 0;
    for (int i=0; i<n; i++){
        // cout << card[i] << ' ';
        sum += card[i];
    }
    
    // cout << '\n';
    cout << sum;
    

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int coin[n+1];
    for (int i=1; i<=n; i++){
        cin >> coin[i];
    }
    
    int cnt = 0;
    int sum = 0;
    int i = n;
    while (sum != k && i > 0){
        if (sum + coin[i] <= k){
            sum += coin[i];
            //cout << sum << '\n';
            cnt++;
        } else i--;
    }
    
    cout << cnt;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long distance[n+1];
    long long oilCost[n+1];
    for (int i=1; i<n; i++){
        cin >> distance[i];
    }
    for (int i=1; i<=n; i++){
        cin >> oilCost[i];
    }
    
    long long minCost = oilCost[1];
    long long sumCost = oilCost[1] * distance[1];
    for (int i=2; i<n; i++){
        minCost = min(minCost, oilCost[i]);
        // cout << "minCost at " << i << " = " << minCost << '\n';
        sumCost += minCost * distance[i];
    }
    
    cout << sumCost;
    
    return 0;
}
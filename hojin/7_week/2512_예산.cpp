#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> budgetreq(n);
    int maxbudgetreq = 0;
    for (int i=0; i<n; i++) {
        cin >> budgetreq[i];
        maxbudgetreq = max(budgetreq[i], maxbudgetreq);
    }
    cin >> m;
    
    int start = 0;
    int end = maxbudgetreq;
    int ans = 0;
    while (start <= end){
        int budgetsum = 0;
        int mid = (start+end) / 2;
        
        for (int i=0; i<n; i++){
            budgetsum += min(budgetreq[i], mid);
        }
        
        if (budgetsum < m) {
            start = mid +1;
            ans = mid;
        }
        else if (budgetsum > m) end = mid-1;
        else {
            ans = mid;
            break;
        }
    }

    cout << ans;
    
    return 0;
}
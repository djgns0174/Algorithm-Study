#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i=0; i<n; i++) cin >> sushi[i];
    
    vector<int> sushiTypeVector(d+1, 0);
    int sushiType = 0;

    int start = 0;
    int end = k-1;
    for (int i=0; i<k; i++){
        if (sushiTypeVector[sushi[i]] == 0) sushiType++;
        sushiTypeVector[sushi[i]]++; 
    }
    int maxSushiType = sushiType + (sushiTypeVector[c]==0 ? 1 : 0);
    // cout << "sushiType: " << sushiType << '\n';

    for (int i=1; i<n; i++){
        sushiTypeVector[sushi[start]]--;
        if (!sushiTypeVector[sushi[start]]) sushiType--;
        start = i%n;
        end = (k-1+i)%n;
        if (!sushiTypeVector[sushi[end]]) sushiType++;
        sushiTypeVector[sushi[end]]++;

        // cout << "i: " << i << '\n';
        // cout << "sushiType: " << sushiType << '\n';
        maxSushiType = max(maxSushiType, sushiType + (sushiTypeVector[c]==0 ? 1 : 0));

    }

    cout << maxSushiType;

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    long long z = (100*y/x);
    
    long long start = 0;
    long long end = x;
    long long ans = -1;
    while (start <= end){
        long long mid = (start+end)/2;
        long long bsz = (100*(y+mid)/(x+mid));
        
        if (bsz > z) {
            ans = mid;
            end = mid-1;
        }
        else start = mid+1;

    }
    
    cout << ans;
    
    return 0;
}
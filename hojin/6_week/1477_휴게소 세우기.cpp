
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    int rest[n+2];
    rest[0] = 0;
    for (int i=1; i<n+1; i++) cin >> rest[i];
    rest[n+1] = l;
    sort(rest, rest+n+2);
    
    int start = 1;
    int end = l;
    int ans = l;
    int distance;

    while (start <= end){
        int mid = (start+end)/2;
        int restcnt = 0;
        for(int i=0; i<n+1; i++){
            distance = rest[i+1] - rest[i];
            restcnt += (distance-1)/mid;
        }
        if (restcnt > m){
            start = mid+1;
        } else {
            ans = mid;
            end = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}
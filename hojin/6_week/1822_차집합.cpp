
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int na, nb;
    cin >> na >> nb;
    vector<int> a(na);
    vector<int> b(nb);
    for (int i=0; i<na; i++){
        cin >> a[i];
    }
    for (int i=0; i<nb; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int start, end, mid;
    vector<int> ans;
    bool found;
    for (int i=0; i<na; i++){
        start = 0;
        end = b.size()-1;
        found = false;
        while (start <= end){
            mid = (start+end)/2;
            if (b[mid] > a[i]){
                end = mid - 1;
            }
            else if (b[mid] < a[i]){
                start = mid + 1;
            }
            else {
                found = true;
                break;
            }
        }
        if (!found){
            ans.push_back(a[i]);
        }
    }
    
    cout << ans.size()<< '\n';
    
    if (ans.size() > 0){
        for (int i=0; i<ans.size(); i++){
            cout << ans[i];
            if (i != ans.size()-1) cout << ' ';
        }
    }

    return 0;
}
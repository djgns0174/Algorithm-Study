#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int t, n;
    cin >> t;    
    for (int i=0; i<t; i++){
        cin >> n;
        
        unordered_map<string, int> m;
        string clothes;
        string kind;
        int result = 1;
        
        for (int j=0; j<n; j++){
            cin >> clothes >> kind;
            if (m.find(kind) == m.end()) m[kind] = 1;
            else m[kind] += 1;
        }
        
        for (pair i:m){
            result *= (i.second+1);
        }
        cout << result-1 << '\n';
    }

    return 0;
}
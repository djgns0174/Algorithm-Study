#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, string> m;
    string name;
    string log;
    vector<string> curEnter;
    for (int i=0; i<n; i++){
        cin >> name >> log;
        if (log == "enter") m[name] = log;
        else if (log == "leave") m.erase(name);
    }
    
    for (pair<string, string> i : m){
        curEnter.push_back(i.first);
    }
    sort(curEnter.begin(), curEnter.end(), greater<string>());
    for (string i: curEnter) cout << i << '\n';

    return 0;
}
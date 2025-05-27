#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> chars;


void bt(int start, int aeioucnt, vector<char> str){
    if (aeioucnt > l-2) return;
    if (str.size()==l && aeioucnt >= 1){
        for (int i=0; i<l; i++) cout << str[i];
        cout << '\n';
        return;
    }
    
    for(int i=start; i<c; i++){
        str.push_back(chars[i]);
        int nextcnt = aeioucnt;
        if (chars[i] == 'a' || chars[i] =='e' || chars[i] =='i' || chars[i] =='o' || chars[i] =='u') nextcnt++;
        bt(i+1, nextcnt, str);
        str.pop_back();
    }
}

int main() {
    
    cin >> l >> c;

    for (int i=0; i<c; i++) {
        char a;
        cin >> a;
        chars.push_back(a);
    }
    sort(chars.begin(), chars.end());

    vector<char> str;
    bt(0, 0, str);

    return 0;
}
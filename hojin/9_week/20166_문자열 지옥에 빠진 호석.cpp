#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, m, k;
vector<vector <char> > chars;
map<string, int> godstr;
vector<string> godstrarr;

void findcase(int x, int y, int godstridx, int cur){
    if (chars[y][x] != (godstrarr[godstridx])[cur]) return;

    if (cur == godstrarr[godstridx].length()-1) {
        godstr[godstrarr[godstridx]] += 1;
        return;
    }

    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i=0; i<8; i++){
        int nx = ((x+m)+dx[i])%m;
        int ny = ((y+n)+dy[i])%n;
        findcase(nx, ny, godstridx, cur+1);
    }

}

int main() {
    
    cin >> n >> m >> k;
    chars.resize(n, vector<char>(m));
    

    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            chars[i][j] = s[j];
        }
    }

    for (int i=0; i<k; i++) {
        string str;
        cin >> str;
        godstrarr.push_back(str);
        godstr[str] = 0;
    }

    for (int l=0; l<k; l++){
        if (godstr[godstrarr[l]] > 0){
            cout << godstr[godstrarr[l]] << '\n';
            continue;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++)
                findcase(j, i, l, 0);
        }

        cout << godstr[godstrarr[l]] << '\n';
    }
    

    return 0;
}
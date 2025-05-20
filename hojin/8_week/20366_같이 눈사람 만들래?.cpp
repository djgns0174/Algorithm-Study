#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Snowman{
public:
    int height;
    int snow1;
    int snow2;

    bool operator <(Snowman &snowman){
        return this->height < snowman.height;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> snow(n);
    for (int i=0; i<n; i++) cin >> snow[i];
    
    vector<Snowman> snowmanArr;
    int iter = 0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            Snowman s;
            s.height = snow[i] + snow[j];
            s.snow1 = i;
            s.snow2 = j;
            snowmanArr.push_back(s);
            iter++;
        }
    }
    sort(snowmanArr.begin(), snowmanArr.end());
    // dubug
    // for (int i=0; i<(n*(n-1))/2; i++) cout << snowmanArr[i].height << ' ';
    // cout << '\n';

    int start = 0;
    int end = 1;
    int mindif = 2000000000;
    int dif = 0;
    while(end < snowmanArr.size()){
        if (snowmanArr[start].snow1 == snowmanArr[end].snow1 ||
            snowmanArr[start].snow1 == snowmanArr[end].snow2 || 
            snowmanArr[start].snow2 == snowmanArr[end].snow1 ||
            snowmanArr[start].snow2 == snowmanArr[end].snow2) {
                end++;
                continue;
            }
        dif = snowmanArr[end].height - snowmanArr[start].height;
        mindif = min(dif, mindif);
        // dubug
        // if (mindif == dif) {
        //     cout << "start1: " << snowmanArr[start].snow1 << " , start2: " << snowmanArr[start].snow2 << " , start_h: " << snowmanArr[start].height << '\n';
        //     cout << "end1: " << snowmanArr[end].snow1 << " , end2: " << snowmanArr[end].snow2 << " , end_h: " << snowmanArr[end].height << '\n';
        //     cout << "dif: " << dif << '\n';
        // }

        start++;
        end = start+1;
    }

    cout << mindif;

    return 0;
}
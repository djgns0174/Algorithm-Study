#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cald(int m, int d){
    int totald;
    switch (m){
        case 1:
            totald = d;
            break;
        case 2:
            totald = 31+d;
            break;
        case 3:
            totald = 59+d;
            break;
        case 4:
            totald = 90+d;
            break;
        case 5:
            totald = 120+d;
            break;
        case 6:
            totald = 151+d;
            break;
        case 7:
            totald = 181+d;
            break;
        case 8:
            totald = 212+d;
            break;
        case 9:
            totald = 243+d;
            break;
        case 10:
            totald = 273+d;
            break;
        case 11:
            totald = 304+d;
            break;
        case 12:
            totald = 334+d;
            break;
    }
    return totald;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> flower(n);
    int m, d;
    for (int i=0; i<n; i++){
        cin >> m >> d;
        flower[i].first = cald(m, d);
        cin >> m >> d;
        flower[i].second = cald(m, d);
    }
    sort(flower.begin(), flower.end());
    int flowerend = 60;
    int flowercnt = 0;
    int iter = 0;
    while(flowerend <= 334 && iter < n){
        bool flowerchecked = false;
        int maxflowerend = flowerend;
        for (int i=0; i<flower.size(); i++){
            if (flower[i].first <= flowerend && flower[i].second > maxflowerend){
                flowerchecked = true;
                maxflowerend = flower[i].second;
                flower.erase(flower.begin() + i);
                i--;
            }
        }
        
        // cout << "iter " << iter << "\n";
        // for (int i=0; i<flower.size(); i++){
        //     cout << flower[i].first << ' ' << flower[i].second << '\n';
        // }
        flowerend = maxflowerend;
        // cout << flowerend << '\n';
        if (flowerchecked) flowercnt++;
        iter++;
    }   
    
    if (flowerend < 335) flowercnt = 0;
    cout << flowercnt;
    
    return 0;
} 
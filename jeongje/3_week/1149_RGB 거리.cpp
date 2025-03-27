#include <iostream>
#include <algorithm>

using namespace std;

static int rgb[1001][3];

int main(){
    // 같은 색이 연속되면 안됨
    int N;
    cin >> N;
    
    rgb[0][0] = 0;
    rgb[0][1] = 0;
    rgb[0][2] = 0;
    
    for(int i=1;i<=N;i++){
        int r_cost, g_cost, b_cost;
        cin >> r_cost >> g_cost >> b_cost;
        
        rgb[i][0] = min(rgb[i-1][1], rgb[i-1][2]) + r_cost;
        rgb[i][1] = min(rgb[i-1][0], rgb[i-1][2]) + g_cost;
        rgb[i][2] = min(rgb[i-1][0], rgb[i-1][1]) + b_cost;
    }
    
    cout << min({rgb[N][0], rgb[N][1], rgb[N][2]});
}
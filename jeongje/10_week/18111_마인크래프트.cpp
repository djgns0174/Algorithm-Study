#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

static int map[500][500];

int main(){
    int N, M, B;
    cin >> N >> M >> B;

    int maxHeight = 0;
    int minHeight = 256;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
            if(maxHeight < map[i][j]) maxHeight = map[i][j];
            if(minHeight > map[i][j]) minHeight = map[i][j];
        }
    }

    // 최소 높이 ~ 최대 높이까지 고르기 작업 다 해보고 
    // 그 중에서 제일 적은 시간을 고르기 
    int minimumTime = INT_MAX;
    int heightInMinimunTime = 0;
    for(int h = minHeight; h <= maxHeight; h++){
        
        int time = 0;
        int now_B = B;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) {
                if(map[i][j] > h) { // 땅을 파야 되는 경우 
                    now_B += map[i][j] - h;
                    time += (map[i][j] - h) * 2;
                } else if (map[i][j] < h) { // 땅을 쌓아야 되는 경우
                    now_B -= h - map[i][j];
                    time += (h - map[i][j]);
                } else {  // 고르기 작업을 안해도 되는 높이 
                    continue;
                }
            }     
        }

    if (now_B >= 0) { 
        if (time < minimumTime) 
        {
            minimumTime = time;
            heightInMinimunTime = h;
        } 
        // 같은 시간인 경우 더 높은 높이를 선택하기 위해서 
        else if (time == minimumTime && h > heightInMinimunTime) 
        {
            heightInMinimunTime = h;
        }
    }
    
    }


    cout << minimumTime << " " << heightInMinimunTime;

    return 0;
}
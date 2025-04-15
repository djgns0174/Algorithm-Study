#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

#define endl "\n"

using namespace std;

/*
    [그리디]
    3월 2일 이전의 꽃
    - 만약 3월 1일 이전에 피고 11월31일 이후에 지는 꽃이 있으면 1출력 후 종료
    - 3월 1일 이전에 피고 3월 1일 이후에 지면 
        - 정원에 꽃이 없으면 심는다.
        - 정원에 꽃이 있으면 이전 꽃과 현재 꽃을 비교해서 더 오래가는 꽃을 심는다.
    - 3월 1일 이후의 개화시기 꽃이 나타나면 해당 반복문 종료

    3월 2일 이후의 꽃
    - 현재 꽃은 이전 꽃이 지는 시기보다 빨리 시작해야된다. (같아도됨)
    - 현재 꽃은 이전 꽃이 지는 시기보다 늦게 져야된다. (같으면 안됨)
    - 현재 꽃이 이전 꽃 피는 시기보다 느려야 된다.
    - 만약 현재 꽃이 같거나 더 빠르면 이전 꽃은 빼고 현재 꽃을 심는다.
    - 현재 꽃이 더 느리면 이전꽃들을 전부 탐색해서 이전꽃의 지는 시기와 현재꽃의 개화시기의 차이가 가장 적은 인덱스를 찾고 해당 인덱스 부터 끝까지 삭제한 뒤 현재 꽃을 심는다.

    11월 31일 이후에 지는 꽃 심었을때
    - 종료

    정답출력
    - 맨 처음 꽃의 개화시기와 맨 마지막 꽃의 지는시기를 확인
        - 올바르면 정원의 꽃 개수 출력
        - 그렇지 않다면 0 출력

    [시간 복잡도]
    처음 정렬할때(nlogn) + 전체탐색(n) = 약 1,661,000
*/

int main(void){

    int n;
    cin >> n;

    vector<array<int,4>> flower(n);
    for(int i=0; i<n; i++){
        cin >> flower[i][0] >> flower[i][1] >> flower[i][2] >> flower[i][3];
    }

    sort(flower.begin(), flower.end(), [](const array<int, 4>& a, const array<int, 4>& b){
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];       
        if (a[2] != b[2]) return a[2] < b[2];       
        return a[3] < b[3];                         
    });

    vector<array<int,4>> garden;
    int start = 1;
    for(int i=0; i<n; i++){

        int startValue = flower[i][0]*100 + flower[i][1];
        int endValue = flower[i][2]*100 + flower[i][3];
        
        if(startValue <= 301 && endValue >= 1131){
            cout << 1 << endl;
            return 0;
        }

        if(startValue <= 301 && endValue >= 301){
            if(garden.empty()) garden.push_back(flower[i]);

            else if(garden.back()[2] < flower[i][2] || (garden.back()[2] <= flower[i][2] && garden.back()[3] < flower[i][3])){
                garden.pop_back(); garden.push_back(flower[i]);
            }
        }

        if(startValue > 301) {
            start = i;
            break;
        }
    }

    // test
    // for(int i=0; i<garden.size(); i++){
    //     cout << garden[i][0] << garden[i][1] << garden[i][2] << garden[i][3] << endl;
    // }

    for(int i=start; i<n; i++){
        int flowerStartMonth = flower[i][0];
        int flowerStartDate = flower[i][1];
        int flowerEndMonth = flower[i][2];
        int flowerEndDate = flower[i][3];
        
        if(garden.empty()) garden.push_back(flower[i]);

        else if(flowerStartMonth < garden.back()[2] || (flowerStartMonth <= garden.back()[2] && flowerStartDate <= garden.back()[3])){

            if(flowerEndMonth > garden.back()[2] || (flowerEndMonth >= garden.back()[2] && flowerEndDate > garden.back()[3])){

                if(flowerStartMonth > garden.back()[0] || (flowerStartMonth >= garden.back()[0] && flowerStartDate > garden.back()[1])){
                    int minDiff = 2147483647;
                    int minDiffIdx = 0;
                    for(int j=garden.size()-1; j>=0; j--){
                        int diff = (garden[j][2]*100 + garden[j][3]) - (flowerStartMonth*100 + flowerStartDate);
                        if(diff < 0) break;
                        if(diff < minDiff){
                            minDiff = diff;
                            minDiffIdx = j;
                        }
                    }
                    for(int j=minDiffIdx; j<garden.size()-1; j++){
                        garden.pop_back();
                    }
                    garden.push_back(flower[i]);
                }

                else {
                    garden.pop_back();
                    garden.push_back(flower[i]);
                }
            }
        }

        else {
            cout << 0 << endl;
            return 0;
        }

        if(flowerEndMonth > 11) break;
    }

    //test
    // for(int i=0; i<garden.size(); i++){
    //     cout << garden[i][0] << garden[i][1] << garden[i][2] << garden[i][3] << endl;
    // }
    // cout << endl;

    int startValue = garden[0][0]*100 + garden[0][1];
    int endValue = garden[garden.size()-1][2]*100 + garden[garden.size()-1][3];

    if(startValue <= 301 && endValue >= 1131){
        cout << garden.size() << endl;
    }
    else {
        cout << 0 << endl;
    }

    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define endl "\n"

using namespace std;

/*
    [그리디]
    1. 시작 시간으로 정렬. 강의실 한개 생성. 끝난 시간과 다음 시작 시간이 가장 짧은 강의를 붙인다. 계속 붙인 뒤 더이상 붙일 강의가 없으면 다음 반복문으로 넘어감. 강의실 새로 생성해서 다시 반복한다.
    2. 시작 시간으로 정렬. 우선순위 큐를 사용해서 가장 빨리 끝나는 강의실을 대기시켜놓는다. 현재 강의가 강의실보다 먼저 시작하면 우선순위 큐에 강의(강의 끝나는 시간)을 추가한다. 강의실 끝나고 강의가 시작된다면 큐에 있는 값을 빼고 현재 강의가 끝나는 시간을 넣는다(강의 끝나는 시간 업데이트). 위 과정을 모든 강의에 적용하고 큐의 사이즈를 보면 된다.

    [시간 복잡도]
    1. 20만 제곱 = 400억으로 n^2으로 풀지 못한다.
    2. 퀵정렬(nlogn) + 전체 탐색(n) = 20만log20만 = 약 3,524,000

    -> 2번 방법을 적용했을때 통과
*/

int main(void){

    priority_queue<int, vector<int>, greater<int>> room;

    int n;
    cin >> n;

    vector<pair<int, int> > lecture(n);

    for(int i=0; i<n; i++){
        cin >> lecture[i].first >> lecture[i].second;
    }

    sort(lecture.begin(), lecture.end());

    room.push(lecture[0].second);
    int roomIdx = 0;
    for(int i=1; i<n; i++){
        int lectureStart = lecture[i].first;
        int lectureEnd = lecture[i].second;
        int roomEnd = room.top(); 

        if(lectureStart < roomEnd)
            room.push(lectureEnd);
        else {
            room.pop(); room.push(lectureEnd);
        }
    }

    cout << room.size() << endl;
        
    return 0;
}
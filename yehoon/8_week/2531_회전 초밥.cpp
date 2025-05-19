#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

/*
    회전 초밥 - 2531

    [그리디]
    1. 첫번째 초밥을 완전탐색으로 선택한다.
    2. 첫번째 초밥부터 k만큼 집합에 담는다.
    3. 집합의 사이즈를 answer에 저장하고 1번 반복문을 반복한다.

    [그리디 시간복잡도]
    n(완전탐색) * klogk(k만큼 집합에 담고 해당 집합에서 원소가 중복되는것이 있는지 확인)
    결과 : 시간초과

    [슬라이딩 윈도우]
    맨 앞 원소는 빼고 새로운 원소를 뒤에 추가하는 방식
    1. 첫번째 초밥을 완전탐색으로 선택한다.
    2. 윈도우 크기 만큼 배열에 담는다.
    3. 맨 앞 원소가 윈도우에 존재하지 않다면 size를 하나 빼준다.
    4. 추가할 원소가 윈도우에 존재하지 않다면 size를 하나 더한다.
    5. 쿠폰이 윈도우에 존재하지 않다면 사이즈를 더해서 answer에 저장한다.

    [슬라이딩 윈도우 시간복잡도]
    n(완전탐색) * 2logk(중복된 원소가 있는지 검사하고 원소 제거 및 추가)
*/

int main(void)
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int size = 0;
    vector<int> eat;
    for(int i=0; i<k; i++) 
    {
        if(find(eat.begin(), eat.end(), arr[i]) == eat.end())
            size++;
        eat.push_back(arr[i]); 
    }

    int answer = 0;
    if(find(eat.begin(), eat.end(), c) == eat.end()) answer = max(0, size + 1);
    else answer = max(0, size);

    for(int i=1; i<n; i++)
    {
        // test
        // cout << endl;
        // cout << size << endl;
        // for(int j=0; j<eat.size(); j++) cout << eat[j] << " " ;
        // cout << endl;

        int pushValue = arr[(i+k-1)%n];
        int popValue = eat.front();

        if(find(eat.begin()+1, eat.end(), popValue) == eat.end())
            size--;
        
        eat.erase(eat.begin());

        if(find(eat.begin(), eat.end(), pushValue) == eat.end())
            size++;

        eat.push_back(pushValue);


        // for(int j=0; j<k; j++) eat.insert(arr[(i+j)%n]); 슬라이딩 윈도우 적용 안한 버전

        if(find(eat.begin(), eat.end(), c) == eat.end()) answer = max(answer, size + 1);
        else answer = max(answer, size);
    }

    cout << answer << endl;

    return 0;
}
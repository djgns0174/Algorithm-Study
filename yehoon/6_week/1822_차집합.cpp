#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
[이분탐색]
- A 와 B의 원소들을 오름차순으로 정렬한다.
- B의 원소의 값을 A에서 이분탐색 후 값을 검색해서 해당 값을 집합 A에서 빼준다.
- B 원소가 사라질 때까지 똑같이 진행한다.

[시간복잡도]
- 집합 B 탐색 (n) * 집합 A 탐색 후 이분탐색으로 값 검색(logn) = nlogn
- 50만log(50만) = 약 9500만으로 시간통과

[틀린 이유] 
- 이분탐색을 해서 해당 값을 집합 A에서 빼는 과정에서 배열을 한칸씩 앞으로 땡겨야 하기 때문에 n 시간이 걸리게 된다. 그래서 n^2log(n)이 소요되므로 시간초과 난다.

[range 변수]
- 오름차순으로 정렬했기 때문에 B 원소값을 A에서 검색을 다 했으면 해당 원소값 인덱스부터(key) A를 시작해서 탐색한다.

*/

int main(void){

    int n, m;
    cin >> n >> m;

    vector<int> a;
    vector<int> b;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }

    for(int i=0; i<m; i++){
        int input;
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int range = 0;
    for(int i=0; i<m; i++){
        int target = b[i];
        int start = range;
        int end = a.size();
        int key = (start + end) / 2;

        //이분탐색
        while(start <= end){
            if(a[key] == target){
                a[key] = -1;
                n--;
                break;
            }
            if(a[key] < target){
                start = key + 1;
            } else {
                end = key - 1;
            }
            key = (start + end) / 2;
        }
        range = key;
    }
    
    int size = a.size();
    cout << n << endl;
    for(int i=0; i<size; i++){
        if(a[i] == -1) continue;
        if(i == size-1)
            cout << a[i] << endl;
        else 
            cout << a[i] << " ";
    }
    
    return 0;
}
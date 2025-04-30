#include<iostream>
#include<vector>

#define endl "\n"

using namespace std;

/*
    가장 긴 증가하는 부분 수열 - 12015

    [이분탐색]
    1. 이분탐색을 사용해야되는 이유
        1. 최대 입력 개수가 100만이다. dp접근법을 사용하면 최악의 경우 n^2이 나오므로 시간초과가 생긴다. 이전 값(본인보다 작고 가장 긴 수열)을 찾으려면 이분탐색을 사용해서 nlogn으로 시간을 줄여야된다.
    2. 풀이
        1. 완전탐색으로 하나씩 선택한다.
        2. 처음 값은 배열에 삽입한다.
        3. 둘째부터
            1. 현재 값이 배열의 마지막 수 보다 크면 부분수열에 삽입한다.
            2. 마지막 수 보다 작으면 이분탐색으로 들어갈 자리에 삽입한다.
            3. 해당 자리의 값을 현재 값으로 갱신한다.
        4. 부분수열의 길이가 정답이 된다.

    [시간복잡도]
    n(완전탐색으로 하나씩 선택) * logn(이분탐색으로 들아갈 자리 찾기)
    = nlogn 으로 통과

    [틀린 이유]
    Key 값을 사용하는것이 아니라 start값을 사용해야됨
    이분탐색의 원리에 따라서 start와 end가 좁혀지면서 원하는 값을 탐색하는 것이다.
    아래 코드에서는 마지막에 원하는 값(들어갈 자리)은 start가 된다.
    key값은 원하는 값 전의 값이 되므로 틀릴 여지가 있다. 
    
    원하는 값을 찾았을 때 end값은 계속 감소하므로 마지막의 key값은 원하는값 바로 이전
    값이 된다.(start - 1)

                while(start <= end)
                {
                    key = (start + end) / 2;
                    if(lis[key] < arr[i]) start = key + 1;
                    else end = key - 1;
                }
                while(start <= end)
                {
                    key = (start + end) / 2;
                    if(lis[key] < arr[i]) start = key + 1;
                    else end = key - 1;
                }
 

*/

int main(void)
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<int> lis;
    lis.push_back(arr[0]);
    
    for(int i=1; i<n; i++)
    {
        int lastIdx = lis.size() - 1;

        if(lis[lastIdx] < arr[i]) lis.push_back(arr[i]);
        else if(lis[lastIdx] == arr[i]) continue;
        else
        {
            int start = 0;
            int end = lis.size() - 1;
            int key;
            while(start <= end)
            {
                key = (start + end) / 2;
                if(lis[key] < arr[i]) start = key + 1;
                else end = key - 1;
            }

            lis[start] = arr[i];
            // list[key] = arr[i];  -> 틀린 이유 ! 
        }
    }

    cout << lis.size() << endl;

    return 0;
}
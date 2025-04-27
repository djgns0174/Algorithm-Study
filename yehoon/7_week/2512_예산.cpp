#include<iostream>
#include<algorithm>
#include<queue>

#define endl "\n"

using namespace std;

/*
    예산 - 2512

    [그리디]
    1. 예산 요청 금액을 정렬한다.
    2. 예산 요청 금액의 합을 구한다.
        1. 금액의 합이 예산보다 작으면 최대 예산 출력하고 종료
    3. (금액의 합 / 지방수)를 초기 예산으로 잡는다.
    4. 지방에서 실제로 사용하는 예산비용을 전부 더해서 국가예산과 비교한다.
    5. 예산을 더 사용하는 지방들에게 남는 예산을 나눠준다.
    6. 배정된 예산으로 한해서 다시 4,5번을 반복하고 나눠주는 예산이 0이될때까지 진행한다.
    7. [시간복잡도]
        nlogn(정렬비용) + n(완전 탐색으로 남는 예산을 구하는 비용)
        = nlogn으로 통과
*/

int main(void){

    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int m;
    cin >> m;

    sort(arr.begin(), arr.end());

    if(sum < m)
    {
        cout << arr.back() << endl;
    }
    else 
    {
        int giveBudget = m / n;
        
        while(1)
        {

            int useBudget = 0;
            int idx = 0;

            for(int i=0; i<n; i++)
            {
                if(arr[i] <= giveBudget)
                {
                    useBudget += arr[i];
                }
                else
                {
                    idx = i;
                    break;
                }
            }
            useBudget += giveBudget * (n-idx);

            int restBudget = m - useBudget;
            int giveRestBudget = restBudget / (n - idx);

            if(giveRestBudget <= 0) break;

            giveBudget += giveRestBudget;
        }

        cout << giveBudget << endl;
    }
    
    return 0;
}
#include<iostream>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    세수의 합

    [이분탐색]
    1. 큰수부터 세수의 합 선택
    2. 해당 값이 세수의 합이 되는지
        1. 첫번째, 두번째값 완전탐색으로 결정
        2. 세번째 값 이진탐색으로 탐색해서 존재하면 break, 그렇지 않으면 계속 반복

    [시간복잡도]
    n(세수의 합 선택) * n^2(첫번째, 두번째 값 완전탐색) * log2(n)(이진탐색)
    = n^3 * log2(n) 으로 시간초과가 날 가능성이 있지만 
    정답을 찾았을 경우 중간에 break로 빠져 나오기 때문에 정답될 가능성도 있다고 판단.

    결과 -> 시간초과

    [해결방법]
    사전에 두번째, 세번째 값의 합들의 모든 경우의 수를 배열에 저장하고
    첫번째 값만 완전탐색으로 결정한다.
    나머지 값이 배열에 이진탐색으로 존재하는 경우 정답이 나오므로 break한다.

    1. 큰수부터 세수의 합 선택
    2. 해당 값이 세수의 합이 되는지
        1. 첫번째값 완전탐색으로 결정
        2. 세수의 합 - 첫번째값을 찾아야된다.
        3. 두번째, 세번째 값 더한 배열에서 나오면 합이 되므로 break, 안되면 반복

    [개선된 시간복잡도]
    n^2(두번째, 세번째 값의 합들의 모든 경우 저장) + 
    n(세수의 합 선택) * n(첫번째값 완전탐색) * log2(n)(나머지 값 이진탐색)
    = n^2log2(n) 으로 시간복잡도 통과함
    
*/

vector<int> two_value_sum;

int main(void){

    int n;
    cin >> n;

    vector<int> u;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        u.push_back(input);
    }

    sort(u.begin(), u.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            two_value_sum.push_back(u[i]+u[j]);
        }
    }

    sort(two_value_sum.begin(), two_value_sum.end()); // 이분탐색을 하기 위해서는 무조건 정렬!

    int answer;
    for(int i=n-1; i>=0; i--){
        answer = u[i];
        for(int j=0; j<i; j++){
            int first = u[j];
            int rest = answer - first;
            if(binary_search(two_value_sum.begin(), two_value_sum.end(), rest)){
                cout << answer << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
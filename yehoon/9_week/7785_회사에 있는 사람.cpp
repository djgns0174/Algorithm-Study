#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define endl "\n"

using namespace std;

/*
    회사에 있는 사람

    [구현]
    1. 회사에 사람이 들어오면 리스트에 추가한다.
    2. 사람이 나가면 리스트에서 찾아서 제거한다.
    3. 리스트를 정렬 후 출력한다.

    [시간복잡도 분석]
    사람이 나갈때마다 리스트에서 찾아야되기 때문에 n^2
    최악의 경우 최대 입력수는 100만인데 50만이 회사에 들어오고 50만이 나갈때
    50만^2으로 시간초과가 난다. 

    [구현 개선]
    1. 회사에 사람이 들어오면 리스트에 추가한다.
    2. 회사에 사람이 나가면 나가는 리스트에 추가한다.
    3. 리스트 두개를 모두 정렬한다.
    4. 나가는 리스트에서 하나씩 빼서 이분탐색으로 들어온 리스트에서 찾아서 제거한다.
    5. 들어온 리스트를 모두 출력한다.

    [시간복잡도]
    50만 * log2(50만) 로 980만으로 통과
*/

int main(void)
{
    int n;
    cin >> n;

    vector<string> in;
    vector<string> out;

    for(int i=0; i<n; i++)
    {
        string name; string work;
        cin >> name >> work;

        if(work == "enter") in.push_back(name);
        else out.push_back(name);
    }

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    for(int i=0; i<out.size(); i++)
    {
        string target = out[i];
        auto it = lower_bound(in.begin(), in.end(), target);
        if(it != in.end() && *it == target) *it = " ";
    }

    for(int i=in.size()-1; i>=0; i--)
    {
        if(in[i] == " ") continue;
        cout << in[i] << endl;
    }
    
    return 0;
}
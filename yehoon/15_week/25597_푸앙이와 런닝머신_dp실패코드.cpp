#include<iostream>
#include<vector>
#include<stack>

#define endl "\n"

using namespace std;

int main(void)
{
    int X, T;
    cin >> X >> T;

    // 시간이 미터보다 더 많다면 기다렸다가 초당 1미터
    if(X <= T)
    {
        cout << 1 << endl;
        cout << T - X << " " << 1 << endl;

        return 0;
    }

    vector<pair<int,int>>dp = vector<pair<int,int>>(X+1);
    dp[0].first = 0; dp[0].second = 0;
    dp[1].first = 1; dp[1].second = 0;

    for(int i=2; i<=X; i++)
    {
        dp[i].first = dp[i-1].first + 1;
        dp[i].second = i-1;
        if(i>=4) 
        {
            if(dp[i].first > dp[i-4].first + 1)
            {
                dp[i].first = dp[i-4].first + 1;
                dp[i].second = i-4;
            }
        }
        if(i>=8) 
        {
            if(dp[i].first > dp[i-8].first + 1)
            {
                dp[i].first = dp[i-8].first + 1;
                dp[i].second = i-8;
            }
        }
    }

    stack<pair<int,int>>st;

    int cur = X;
    int prev = dp[X].second;
    while(cur != 0)
    {
        pair<int,int> p;
        p.first = dp[prev].first;
        p.second = cur - prev;

        st.push(p);

        cur = prev;
        prev = dp[cur].second;
    }

    vector<pair<int,int>>answer;

    while(!st.empty())
    {
        pair<int,int> p = st.top(); st.pop();

        if(answer.size() == 0) answer.push_back(p);
        else 
        {
            if(p.second != answer.back().second)
            {
                answer.push_back(p);
            }
        }
    }

    if(dp[X].first == T)
    {
        for(pair<int,int> p : answer)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    else if (dp[X].first < T)
    {
        int late_time = dp[X].first - T;

        for(pair<int,int> p : answer)
        {
            cout << late_time + p.first << " " << p.second << endl;
        }
    }
    else cout << -1 << endl;
    
    return 0;
}
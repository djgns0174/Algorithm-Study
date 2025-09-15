#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n = friends.size();
    
    unordered_map<string, int> index;
    for(int i=0; i<n; i++)
    {
        index[friends[i]] = i; 
    }
    
    vector<vector<int>> arr(n, vector<int>(n, 0)); // 주고받은 횟수
    for(string gift : gifts)
    {
        stringstream ss(gift);
        
        string a, b;
        ss >> a >> b;
        
        arr[index[a]][index[b]]++;
    }
    
    vector<int> present_value(n, 0); // 선물지수
    for(int i=0; i<n; i++)
    {
        int give_cnt = 0;
        int get_cnt = 0;
        for(int j=0; j<n; j++)
        {
            give_cnt += arr[i][j];
            get_cnt += arr[j][i];
        }
        
        present_value[i] = give_cnt - get_cnt;
    }
    
    vector<int> get(n, 0);
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i][j] > arr[j][i]) get[i]++;
            else if(arr[i][j] < arr[j][i]) get[j]++;
            else 
            {
                if(present_value[i] > present_value[j]) get[i]++;
                else if(present_value[i] < present_value[j]) get[j]++;
            }
        }
    }
    
    answer = get[0];
    for(int value : get)
    {
        answer = max(answer, value);
    }
    
    return answer;
}
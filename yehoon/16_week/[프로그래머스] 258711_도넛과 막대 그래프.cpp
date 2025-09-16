#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    vector<bool> check(1000001, false);
    for(vector<int> edge : edges)
    {
        check[edge[0]] = true;
        check[edge[1]] = true;
    }
    
    vector<int> fan_in (1000001, 0);
    vector<int> fan_out (1000001, 0);
    
    for(vector<int> edge : edges)
    {
        fan_in[edge[1]]++;
        fan_out[edge[0]]++;
    }
    
    int create_point;
    for(int i=1; i<1000001; i++)
    {
        if(check[i] && fan_in[i] == 0 && fan_out[i] >= 2) create_point = i;
    }
    
    for(vector<int> edge : edges)
    {
        if(edge[0] == create_point) fan_in[edge[1]]--;
    }
    
    int graph_cnt = fan_out[create_point];
    
    int eight = 0; int stick = 0; int donut = 0;
    for(int i=1; i<1000001; i++)
    {
        if(check[i] && fan_in[i] == 2 && fan_out[i] == 2) eight++;
        if(check[i] && fan_in[i] == 1 && fan_out[i] == 0) stick++;
        if(check[i] && fan_in[i] == 0 && fan_out[i] == 0) stick++;
    }
    donut = graph_cnt - (eight + stick);
    
    answer.push_back(create_point);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}
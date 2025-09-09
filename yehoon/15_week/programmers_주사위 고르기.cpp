#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<bool>used;

void sum(vector<vector<int>>dice, vector<int>sum_comb, vector<int>combination)
{
    if(combination.size() == 0)
    {
        //주사위 합 조합 다했을때
    }

    else 
    {
        // 주사위 합 조합
    }
}

void comb(int start, int n, int r, int depth, vector<int>combination, vector<vector<int>> dice)
{
    if(r == depth)
    {   
        vector<int>sum_comb;
        int first_dice_idx = combination.back(); combination.pop_back();
        for(int i=0; i<6; i++)
        {
            sum_comb.push_back(dice[first_dice_idx][i]);
            sum(dice, sum_comb, combination);
        }
    }
    else 
    {
        for(int i=start; i<=n; i++)
        {
            if(used[i]) continue;
            used[i] = true;
            combination.push_back(i);
            comb(i+1, n, r, depth+1, combination, dice);
            used[i] = false;
            combination.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> dice) 
{
    vector<int> answer;
    
    int n = dice.size();

    used = vector<bool>(n, false);
    vector<int>combination;

    comb(0, n, n/2, 0, combination, dice);
        
    return answer;
}
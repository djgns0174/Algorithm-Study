#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void findSums(const vector<vector<int>>& vectors, int index, int currentSum, vector<int>& sums)
{
    if (index == vectors.size())
    {
        sums.push_back(currentSum);
        return;
    }

    for (int num : vectors[index])
    {
        findSums(vectors, index + 1, currentSum + num, sums);
    }
}

int compare(vector<int>A, vector<int>B)
{
    int aWins = 0;

    for (int a : A)
    {
        for (int b : B)
        {
            if (a > b) { aWins++; }
        }
    }
    return aWins;
}


vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    vector<int> answer;
    vector<int> combination(n, 0);

    // 순열의 처음으로 A가 뒤 주사위를 모두 선택 
    for (int i = n / 2; i < n; i++)
    {
        combination[i] = 1; // 1이면 A가 선택 
    }

    int maxWinNum = 0;
    vector<int> bestCombination;

    do
    {
        vector<vector<int>> diceA, diceB;

        for (int i = 0; i < combination.size(); i++)
        {
            if (combination[i] == 1) diceA.push_back(dice[i]);
            else diceB.push_back(dice[i]);
        }

        vector<int> allSumA, allSumB;
        findSums(diceA, 0, 0, allSumA);
        findSums(diceB, 0, 0, allSumB);

        int nowWin = compare(allSumA, allSumB); // A가 이긴 수 
        if (nowWin > maxWinNum) // A가 제일 많이 이긴 수 기록 
        {
            maxWinNum = nowWin;
            bestCombination = combination;
        }

    } while (next_permutation(combination.begin(), combination.end()));

    for (int i = 0; i < bestCombination.size(); i++)
    {
        if (bestCombination[i] == 1) answer.push_back(i + 1);
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

int find_index(vector<string>&, string);

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    int n = friends.size();
    vector<vector<int>> table(n, vector<int>(n, 0));
    vector<int> gift_power(n);
    vector<int> next_month_result(n);

    for (int i = 0; i < gifts.size(); i++)
    {
        string log = gifts[i];
        string sender, receiver;

        // ���� �������� SPLIT ��Ű�� 
        size_t pos = log.find(' ');
        sender = log.substr(0, pos);
        receiver = log.substr(pos + 1);

        int i_sender = find_index(friends, sender);
        int i_receiver = find_index(friends, receiver);

        // sender -> receiver�� ���� ���� ���� 
        table[i_sender][i_receiver]++;

        // ���������� ���� ���� ����
        gift_power[i_sender]++;

        // �޴����� ���� ���� ���� 
        gift_power[i_receiver]--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (table[i][j] > table[j][i]) next_month_result[i]++;
            else if (table[i][j] < table[j][i]) next_month_result[j]++;
            else // table[i][j] == table[j][i] (���� �ְ� ���� ���� ������ ������) 
            {
                if (gift_power[i] > gift_power[j]) next_month_result[i]++;
                else if (gift_power[i] < gift_power[j]) next_month_result[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (next_month_result[i] / 2 > answer) answer = next_month_result[i] / 2;
    }


    return answer;
}

int find_index(vector<string>& friends, string str)
{
    for (int i = 0; i < friends.size(); i++)
    {
        if (friends[i] == str) return i;
    }
    return -1;
}
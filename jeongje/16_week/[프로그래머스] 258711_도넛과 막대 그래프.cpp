#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    const int MAX = 1000000;
    vector<int> fan_in(MAX + 1, 0);
    vector<int> fan_out(MAX + 1, 0);
    vector<bool> check(MAX + 1, false);

    /////////////////////////////////////////////////////////
    // 1. ��-��, ��-�ƿ� ���
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        fan_out[u]++;
        fan_in[v]++;
        check[u] = check[v] = true;
    }

    /////////////////////////////////////////////////////////
    // 2. ���� �߰��� ��� ã�� (��-���� 0�̰� �� �ƿ��� 2���� ũ�� ���� �߰��� ���)
    int new_node = -1;
    for (int i = 1; i <= MAX; i++) {
        if (check[i] && fan_in[i] == 0 && fan_out[i] >= 2) {
            new_node = i;
            break;
        }
    }

    // 3. �׷��� ���� �з�
    int total = fan_out[new_node]; // ��ü �׷��� ���� 
    int stick = 0, eight = 0;

    for (int i = 1; i <= MAX; i++) {
        if (!check[i] || i == new_node) continue;

        if (fan_out[i] == 0) stick++;     // ���� �׷���
        else if (fan_out[i] == 2) eight++; // 8�� �׷���
    }

    // ���� ���� = ��ü ���� - ���� ���� - 8�� ���� 
    int donut = total - stick - eight; 


    answer.push_back(new_node);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    // 4. ��� ����
    return answer;
}

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
    // 1. 팬-인, 팬-아웃 계산
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        fan_out[u]++;
        fan_in[v]++;
        check[u] = check[v] = true;
    }

    /////////////////////////////////////////////////////////
    // 2. 새로 추가된 노드 찾기 (팬-인이 0이고 팬 아웃이 2보다 크면 새로 추가된 노드)
    int new_node = -1;
    for (int i = 1; i <= MAX; i++) {
        if (check[i] && fan_in[i] == 0 && fan_out[i] >= 2) {
            new_node = i;
            break;
        }
    }

    // 3. 그래프 개수 분류
    int total = fan_out[new_node]; // 전체 그래프 개수 
    int stick = 0, eight = 0;

    for (int i = 1; i <= MAX; i++) {
        if (!check[i] || i == new_node) continue;

        if (fan_out[i] == 0) stick++;     // 막대 그래프
        else if (fan_out[i] == 2) eight++; // 8자 그래프
    }

    // 도넛 개수 = 전체 개수 - 막대 개수 - 8자 개수 
    int donut = total - stick - eight; 


    answer.push_back(new_node);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    // 4. 결과 리턴
    return answer;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, D, K, C;
    cin >> N >> D >> K >> C;

    vector<int> dish(N);
    for (int i = 0; i < N; i++) {
        cin >> dish[i];
    }

    vector<int> dish_check(D + 1, 0);
    int cnt = 0; 

    // 초기 윈도우
    for (int i = 0; i < K; i++) {
        if (dish_check[dish[i]] == 0) cnt++;
        dish_check[dish[i]]++;
    }

    int result = cnt;
    if (dish_check[C] == 0) result++;

    // 슬라이딩 윈도우 시작
    for (int i = 1; i < N; i++) {
        // 제거되는 초밥
        int remove_dish = dish[i - 1];
        dish_check[remove_dish]--;
        if (dish_check[remove_dish] == 0) cnt--;

        // 새로 추가되는 초밥 (회전 벨트이므로 % N)
        int add_dish = dish[(i + K - 1) % N];
        if (dish_check[add_dish] == 0) cnt++;
        dish_check[add_dish]++;

        int temp = cnt;
        if (dish_check[C] == 0) temp++;

        result = result > temp ? result : temp;
    }

    cout << result;
    return 0;
}

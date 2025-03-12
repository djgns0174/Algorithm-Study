#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[9];

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int diff = sum - 100; // 차이 저장

	bool end = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == diff) { // 두 수의 합이 diff와 같으면 두 수가 정답
				arr[i] = 0; // 정렬할 때 제일 앞으로 보내서 거를 수 있도록 0으로 저장
				arr[j] = 0;
				end = true; // 위쪽 for문도 탈출할 수 있도록 
				break;
			}
		}
		if (end)break; // for문 탈출
	}

	sort(arr, arr + 9); // 정렬
	 
	for (int i = 2; i < 9; i++) { // 앞 두개는 범인 이므로 i=2에서 시작
		cout << arr[i] << "\n";
	}

}
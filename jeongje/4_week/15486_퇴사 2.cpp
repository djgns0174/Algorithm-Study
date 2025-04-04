#include <iostream>
#include <vector>

using namespace std;

static vector<int> D, T, P;

int main() {
	int N;
	cin >> N;

	D.resize(N + 2);
	T.resize(N + 1);
	P.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		if (T[i] + i > N + 1) { // 기한 오버
			D[i] = D[i + 1];
		}
		else { // 기한 세이프
			// 현재 일정을 포함하는 거 vs 포함하지 않는 거 더 큰 값을 선택
			D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
		}
	}

	cout << D[1];
}
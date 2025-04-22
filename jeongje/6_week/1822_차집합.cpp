#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int A[500000];
static int B[500000];
static int nA, nB;
static vector<int> v;

bool binary_search(int target);

int main() {
	cin >> nA >> nB;

	for (int i = 0; i < nA; i++)
		cin >> A[i];

	for (int i = 0; i < nB; i++)
		cin >> B[i];


	// 이분탐색의 핵심 (사전에 원소들이 정렬되어 있어야 한다)
	sort(A, A + nA);
	sort(B, B + nB);


	for (int i = 0; i < nA; i++) {
		if (!binary_search(A[i])) {
			v.push_back(A[i]);
		}
	}

	if (v.size()) {
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << 0;
	}

}


bool binary_search(int target) {
	int left = 0;
	int right = nB - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (target == B[mid]) return true;

		if (target < B[mid]) right = mid - 1;
		else left = mid + 1;
	}


	return false;
}
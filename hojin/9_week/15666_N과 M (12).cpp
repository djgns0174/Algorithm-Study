#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> result(8);

void bt(int start, int depth) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=start; i<nums.size(); i++) {
        result[depth] = nums[i];
        bt(i, depth + 1); 
    }
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        if (find(nums.begin(), nums.end(), s) == nums.end()) nums.push_back(s);
    }

    sort(nums.begin(), nums.end());

    bt(0, 0);

    return 0;
}

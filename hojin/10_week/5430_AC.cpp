#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define endl "\n"

int main() {
    int t;
    cin >> t; 

    for (int i=0; i<t; i++){
        string p;
        int n;

        cin >> p >> n;

        string input;
        cin >> input;

        vector<int> arr(n);
        // 슬라이딩 윈도우로 입력 처리
        int start = 1;
        int end;
        for (int j=0; j<n; j++){
            end = start;
            while (end < input.size()-1){
                if (input[end+1] == ',' || input[end+1] == ']'){
                    break;
                } else end++;
            }
            arr[j] = stoi(input.substr(start, end-start+1));
            start = end+2;
        }
        
        bool rev = false;
        // 배열의 시작과 끝을 포인팅
        start = 0;
        end = n-1;
        for (int j=0; j<p.size(); j++){

            if (p[j] == 'R'){
                // vector<int> tmp(n); // 배열을 다 복사해버려서 시간 초과
                // for (int k=0; k<n; k++){
                //     tmp[k] = arr[n-1-k];
                // }
                // swap(tmp, arr);
                rev = !rev;
                int tmp = start;
                start = end;
                end = tmp;
            }

            else if (p[j] == 'D'){
                if (n == 0){
                    cout << "error" << endl;
                    n = -1;
                    break;
                }
                else {
                    if (!rev) start++;
                    else start--;

                    n--;
                }
            }
        }

        // 출력
        if (n >= 0){
            cout << '[';

            if (!rev){
                for (int j=start; j<=end; j++){
                    cout << arr[j];
                    if (j < end) cout << ',';
                }
            } else {
                for (int j=start; j>=end; j--){
                    cout << arr[j];
                    if (j > end) cout << ',';
                }
            }
            
            cout << ']' << endl;
        }
        
    }

    return 0;
}
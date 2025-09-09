#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    int x, t;
    cin >> x >> t;
    
    int n = 1;
    
    int quotient8 = x / 8;
    int rest8 = x % 8;
    int rest8_quotient4 = rest8 / 4;
    int rest8_rest4 = rest8 % 4;
    int minTime = quotient8 + rest8_quotient4 + rest8_rest4;

    int quotient4 = x / 4;
    int rest4 = x % 4;

    int stopTime = 0;

    // 불가능
    if (t < minTime) cout << -1;

    // 1 버튼만
    else if (t >= x){
        stopTime = t-x;
        cout << n << endl;
        cout << stopTime << ' ' << 1;

    }
    // 4 버튼 사용
    else if (t >= quotient4 + rest4){
        stopTime = t - (quotient4 + rest4);
        if (rest4) n++;
        cout << n << endl;
        cout << stopTime << ' ' << 4 << endl;
        if (rest4){
            cout << stopTime + quotient4 << ' ' << 1;
        }

    }
    // 8 버튼 사용
    else {
        // 4 안 써도 됨
        if (t >= quotient8 + rest8){
            stopTime = t - (quotient8 + rest8);
            if (rest8) n++; // 1 사용
            cout << n << endl;
            cout << stopTime << ' ' << 8 << endl;
            if (rest8){
                cout << stopTime + quotient8 << ' ' << 1;
            }
        }
        // 4 써야 됨
        else {
            n++;
            stopTime = t - minTime;
            if (rest8_rest4) n++; // 1 사용
            cout << n << endl;
            cout << stopTime << ' ' << 8 << endl;
            cout << stopTime + quotient8 << ' ' << 4 << endl;
            if (rest8_rest4){
                cout << stopTime + quotient8 + rest8_quotient4 << ' ' << 1;
            }
        }

    }


    return 0;
}
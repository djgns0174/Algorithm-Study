#include<iostream>
#define endl "\n"

using namespace std;

int main(void)
{
    int X, T;
    cin >> X >> T;

    if(X <= T)
    {
        cout << 1 << endl;
        cout << T - X << " " << 1 << endl;

        return 0;
    }

    int a = X / 8;
    int rest8 = X % 8;
    int b = rest8 / 4;
    int c = rest8 % 4;
    int min_time = a + b + c;

    if(T < min_time)
    {
        cout << -1 << endl;
        return 0;
    }

    int a1 = X / 4;
    int b1 = X % 4;
    int time_except_8_button = a1 + b1;

    if(time_except_8_button <= T) // 1, 4 버튼 사용
    {
        int late = T - time_except_8_button;

        if(b1 == 0) // 4 버튼만 사용
        {
            cout << 1 << endl;
            cout << late << " " << 4 << endl;
        }

        else // 1, 4 버튼 사용
        {
            cout << 2 << endl;
            cout << late << " " << 4 << endl;
            cout << late + a1 << " " << 1 << endl;
        }
    }

    else // 1, 4, 8 버튼
    {
        int late = T - min_time;

        if(rest8 == 0 && T >= a) // 8만 사용
        {
            late = T - a;
            cout << 1 << endl;
            cout << late << " " << 8 << endl;
            return 0;
        }

        if(T >= a + rest8) // 1, 8 사용
        {
            late = T - (a + rest8);
            cout << 2 << endl;
            cout << late << " " << 8 << endl;
            cout << late + a << " " << 1 << endl;
            return 0;
        }

        if(T >= min_time)
        {
            if(c == 0) // 4, 8 사용
            {
                cout << 2 << endl;
                cout << late << " " << 8 << endl;
                cout << late + a << " " << 4 << endl;
            }

            else // 1, 4, 8 사용 
            {
                cout << 3 << endl;
                cout << late << " " << 8 << endl;
                cout << late + a << " " << 4 << endl;
                cout << late + a + b << " " << 1 << endl;
            }
        }
    }

    return 0;
}
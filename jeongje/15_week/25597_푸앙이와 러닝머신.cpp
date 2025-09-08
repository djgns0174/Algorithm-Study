#include <iostream>

using namespace std;


int main()
{
    int X, T;
    int four_meter_time, eight_meter_time, one_meter_time;
    cin >> X >> T;
    
    /////////////////////////////////////////////////////////////////////////
    // 1. 버튼 한 번 클릭으로 해결 가능한지 
    
    // 1-1. 초당 1미터 버튼 한 번으로 가능한지 
    if(X <= T)
    {
        cout << "1\n" << T - X << " 1";
        return 0;
    }
    
    // 1-2. 4미터, 8미터 버튼 한 번으로 가능한지 
    for(int i=4;i<=8;i+=4)
    {
        if(X % i == 0)
        {
            if(X / i <= T)
            {
                cout << "1\n" << T - (X / i) << " " << i;
                return 0;
            }
        }
    }
    
    
    
    /////////////////////////////////////////////////////////////////////////
    // 2. 버튼 두 번 클릭으로 해결 가능한지 
    // 버튼 두 번 조합은 (1, 4), (1, 8), (4, 8) 총 세 개 가능하다.
    
    // 2-1. 1미터랑 4미터 조합 확인하기
    four_meter_time = X / 4; // 4미터 속도로 달리는 시간 
    one_meter_time = X % 4;          // 1미터 속도로 달리는 시간 
    if(four_meter_time + one_meter_time <= T)
    {
        int start_time = T - (four_meter_time + one_meter_time);
        cout << "2\n";
        cout << start_time << " 4\n";
        cout << start_time + four_meter_time << " 1\n";
        return 0;
    }
    
    
    // 2-2. 1미터랑 8미터 조합 확인하기 
    eight_meter_time = X / 8; // 8미터 속도로 달리는 시간 
    one_meter_time = X % 8;           // 1미터 속도로 달리는 시간 
    if(eight_meter_time + one_meter_time <= T)
    {
        int start_time = T - (eight_meter_time + one_meter_time);
        cout << "2\n";
        cout << start_time << " 8\n";
        cout << start_time + eight_meter_time << " 1\n";
        return 0;        
    }
    
    
    // 2-3. 4미터랑 8미터 조합 확인하기 
    eight_meter_time = X / 8;
    four_meter_time = (X % 8) / 4;
    one_meter_time = (X % 8) % 4;
    // 아래 식이 나누어 떨어져야 4미터 8미터 2개로 조합 가능 
    if(one_meter_time == 0)
    {
        if(eight_meter_time + four_meter_time <= T)
        {
            int start_time = T - (eight_meter_time + four_meter_time);
            cout << "2\n";
            cout << start_time << " 8\n";
            cout << start_time + eight_meter_time << " 4\n";
            return 0;
        }
    }        
    /////////////////////////////////////////////////////////////////////////
    //
    // 3. 1미터, 4미터, 8미터 버튼 세 개를 모두 써야 되는 경우  
    else
    {
       if(eight_meter_time + four_meter_time + one_meter_time <= T)
        {
            int start_time = T - (eight_meter_time + four_meter_time + one_meter_time);
            cout << "3\n";
            cout << start_time << " 8\n";
            cout << start_time + eight_meter_time << " 4\n";
            cout << start_time + eight_meter_time + four_meter_time << " 1\n";
            return 0;
        } 
    }

    
    /////////////////////////////////////////////////////////////////////////
    // 4. 모든 경우가 불가능한 경우 
    cout << -1;
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int X, Z;
    long long Y;
    cin >> X >> Y;
    
    Z = Y * 100 / X;
    
    if(Z >= 99) // 승률이 절대 변할 수 없는 경우 
    { 
        cout << -1;
    } 
    else 
    {
        int left = 0;
        int right = 1000000000;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            int new_Z = (Y + mid) * 100 / (X + mid);
            
            if(Z < new_Z) right = mid - 1;
            else left = mid + 1;
        }
        
        cout << left;
    }
    
}
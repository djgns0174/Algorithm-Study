#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answer = 0;
    for(int i=0; i<n; i++){
        int target = a[i];

        int start = 0;
        int end = n-1;
        
        while(start < end){
            int value = a[start] + a[end];

            if(value == target)
            {
                if(start != i && end != i)
                {
                    answer++;
                    break;
                }
                else if(start == i) start++;
                else end--;
            } 
            else if(value < target) start++;
            else end--;
        }
    }

    cout << answer << endl;
    
    return 0;
}
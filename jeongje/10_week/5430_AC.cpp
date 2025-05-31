#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int T;
    cin >> T;
   
    for(int t=0;t<T;t++) {
        string p, strn;
        int n;
       
        bool errorCheck = false;
        bool reverse = false;
       
        cin >> p >> n >> strn;
       
        deque<int> dq;
       
        string token = "";
       
        for(int i=1; i<strn.size(); i++)
        {
           
            if(strn[i] == ',' || strn[i] == ']')
            {
                if(!token.empty()) {
                    dq.push_back(stoi(token));
                    token = "";   
                }
            }
            else
            {
                token += strn[i];
            }
        }

       
        for(int i=0;i<p.size();i++)
        {
            if (p[i] == 'R')
            {
                reverse = !reverse;
            }
            else if (p[i] == 'D')
            {
                if(dq.empty())
                {
                    errorCheck = true;
                    break;
                }
                else
                {
                    if(reverse) dq.pop_back();
                    else dq.pop_front();                    
                }
            }
        }
       
        if(errorCheck)
        {
            cout << "error\n";
            continue;
        }
       
        if(!reverse)  // 순방향
        {
            cout << "[";
            for(int i=0;i<dq.size();i++){
                if( i == dq.size() - 1) cout << dq[i];
                else cout << dq[i] << ",";
            }
            cout << "]\n";
        }
        else // 역방향
        {
            cout << "[";
            for(int i=dq.size()-1;i>-1;i--){
                if( i == 0) cout << dq[i];
                else cout << dq[i] << ",";
            }
            cout << "]\n";
        }
       
    }
}

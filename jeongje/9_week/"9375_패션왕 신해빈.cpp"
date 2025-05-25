#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int T;
    cin >> T;
    
    
    for(int i=0;i<T;i++) {
        map<string, int> m;   
        int N;
        cin >> N;
        
        string name, type;
        for(int i=0;i<N;i++){
            cin >> name >> type;
            
            if(m.find(type) == m.end()) {
                m.insert({type, 1});
            } else {
                m[type]++;
            }
        }
        
        if(m.size() == 1) {
            cout << m[type] << "\n";
        } else {
            int cnt = 1;
            
            for(auto iter = m.begin(); iter != m.end(); iter++){
                cnt *= (iter->second + 1); // 옷의 개수 + 안 입는 경우
            }
            
            cout << cnt - 1 << "\n"; // 알몸인 상태 1 빼주기 
        }
    }
}

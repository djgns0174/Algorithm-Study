#include <iostream>
#include <map>

using namespace std;


int main(){
    int N;
    cin >> N;
    
    map<string, string> m;
    
    for(int i=0;i<N;i++){
        string name, log;
        cin >> name >> log;
        
        if(m.find(name) == m.end()) {
            m.insert({name, log});
        } else {
            m.erase(name);
        }
    }
    
    for(auto iter = m.rbegin(); iter != m.rend(); iter++) {
        cout << iter->first <<"\n";
    }
}
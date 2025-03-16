#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, Z, M;
    cin >> N >> Z >> M;
    
    vector<int> field(N+1, 1);
    vector<int> visited(N+1, false);
    
    for(int i=0;i<M;i++){ // 장애물 위치 입력
        int danger;
        cin >> danger;
        field[danger] = 0;
    }
    
    int k=1;
    int position = 1;
    
    while(true) {
        if(position == Z) { // 목적지 달성
            cout << k;
            return 0;
        }
        
        if(!visited[position]) { // 아직 방문 안 했다면
            visited[position] = true; // 방문 배열 체크
        
            if(field[position]) { // 장애물이 없다면
                position += k;  // 다음 목적지
            
                if(position > N) { // N을 넘어서면 빼주기
                    position -= N;
                }             
            } else { // 장애물이 있다면 (해당 k로는 목표달성 불가)
                k++; // 다음 k값으로
                position = 1; // 다시 1로
                fill(visited.begin(), visited.end(), false); // 방문배열 초기화
            }
            
        } else { // 이미 방문 했다면 (다시 똑같이 무한루프 돌 것임)
            fill(visited.begin(), visited.end(), false); // 방문배열 초기화
            position = 1; // 다시 1로
            k++; // 다음 k값으로
        }
    }
}
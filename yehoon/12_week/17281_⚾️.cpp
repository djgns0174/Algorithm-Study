#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"

using namespace std;

/*
    ⚾︎ - 17281 

    1. 타순을 결정한다.
    2. 각 이닝 당 점수를 구한다.
    3. 경기가 끝나면 점수를 저장한다. 
    4. 가장 큰 점수를 출력한다. 

    타순을 결정
    - 순열로 구현

    아인타의 미래 결과
    - 타순이 결정되면 선수별로 각 이닝에서 어떤 결과를 내는지에 대한 배열을 생성한다. 

    진루 상황 배열 : 
    - [0,1,2,3,4]
    - 타석은 0이고 무조건 1으로 초기화 
    - 4번에는 1이상 값이 들어올 수 있으며 득점자리이다. 만약 3이 있으면 주자가 3명 홈으로 들어왔다는것을 의미한다. 
    - 배열의 값은 0 또는 1 로 해당 루상에 주자가 있냐 

    게임 진행 : 
    - 반복문으로 계속 돌리고 out_count 가 3 * 이닝수 가 되면 종료
    -  안타가 나왔을 때 
        - 진루할 베이스 = 현재 베이스(cur) + 안타(정수)
        - 진루할 베이스가 3루를 초과한다면 점수 ++
        - 그렇지 않다면 1~3루까지 모두 따짐
            - 현재 베이스에 주자가 존재하면
            - 현재 베이스의 주자가 진루할 베이스로 이동하기 때문에 
                - base[진루할 베이스] = 1 / base[현재] = 0
    - 아웃 됐을때 : out_count++
        - 게임이 종료될때
            - If out_count == out * 이닝수
            - 게임 점수를 저장
        - 이닝이 종료될때
            - If out_count % 3 == 0
            - 진루 상황 배열 모두 초기화 ( 0번자리 1로, 나머지 0으로)
            - 반복문 계속
    - 다음 타자가 타석에 선다
        - base[0] = 1 , cur_player = (cur_player + 1) % 9 

    [시간복잡도]
    최악의 경우
    타순 결정 (8*7*…*1) * 게임진행(24타자 * 9이닝 * 4(진루 상황 배열 처리))
    = 약 3000만으로 시간통과

    [팁]
    - 이런 복잡한 프로그램을 구현할 때는 각각의 기능들을 구분해서 테스트를 진행한 후 통합 테스트를 하면 좀 더 수월하게 테스팅을 진행할 수 있다. 
    - 에러 메시지를 자세하게 써놓으면 디버깅할때 편하고 더 빠르게 구현할 수 있다. 

    -> 타순을 결정하는 함수, 게임 진행하여 점수를 내는 함수 
    위의 두 함수를 별도로 구분해서 테스트를 진행하면 좀 더 쉽게 구현할 수 있다.
*/

priority_queue<int>answers;
int n;

struct player{
    vector<int> can_score;
};
player p[9];

bool used[10];
vector<int>permutation;
void perm(int depth)
{
    if(depth == 9)
    {
        // 1번선수가 4번타자가 아니면 
        if(permutation[3] != 1) return;
        
        // 1번 선수가 4번타자 라면
        else 
        {
            // 아인타의 미래 결과
            vector<vector<int>> score_board(n, vector<int>(9));

            for(int j=0; j<permutation.size(); j++)
            {
                int player_number = permutation[j] - 1;

                for(int i=0; i<n; i++)
                {
                    score_board[i][j] = p[player_number].can_score[i];
                }
            }

            // 진루 상황 배열
            vector<int> base(4, 0); base[0] = 1;

            // 게임 진행
            int out_count = 0;
            int inning = 0;
            int cur_player = 0;
            int score = 0;
            while(1)
            {
                // 게임 종료
                if(out_count >= 3 * n)
                {
                    // 점수 저장
                    answers.push(score); 
                    break;
                }
                
                // 안타일때 
                if(score_board[inning][cur_player] != 0)
                {
                    for(int i=3; i>=0; i--)
                    {
                        // 루상에 주자가 있을때
                        if(base[i])
                        {
                            int next_base = i + score_board[inning][cur_player];
                            
                            // 홈으로 들어왔을때
                            if(next_base >= 4) score++;

                            // 진루만 했을때
                            else base[next_base] = 1;

                            base[i] = 0; // 기존 베이스에는 진루했으니 주자 없다.
                        }
                    }

                }

                // 아웃일때
                else
                {
                    out_count++;

                    // 이닝 종료시
                    if(out_count % 3 == 0)
                    {
                        // 진루 상황 배열 초기화
                        base = vector<int>(4,0);
                        inning++;
                    }
                }

                base[0] = 1; cur_player = (cur_player + 1) % 9; // 다음 타자가 타석에 선다.
            }
        }
    }
    
    // 타순 결정
    else 
    {
        for(int i=1; i<=9; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                permutation.push_back(i);

                perm(depth + 1);

                used[i] = false;
                permutation.pop_back();
            }
        }
    }
}

int main(void)
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<9; j++){
            int score; cin >> score;
            p[j].can_score.push_back(score);
        }
    }

    perm(0);

    cout << answers.top() << endl;

    return 0;
}
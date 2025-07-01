#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

static int arr[51][10];
static int order[10];
static bool visit[10];

static int maxSore;

int N;

void DFS(int count);
void startGame();

int main() 
{
    cin >> N;
    
    for(int i=1;i<=N;i++) 
    {
        for(int j=1;j<=9;j++) 
        {
            cin >> arr[i][j];
        }
    }
    
    order[4] = 1;
    visit[4] = true;
    
    DFS(2);
    
    cout << maxSore;
}


void DFS(int count)
{
    if(count == 10)
    {
        startGame();
        /*
        for(int i=1;i<=9;i++){
            cout << order[i] << " ";
        }
        cout << endl;
        */
        return;
    }
    
    for(int i=1;i<=9;i++)
    {
        if(visit[i] == true) continue;
        
        visit[i] = true;
        order[i] = count;
        
        DFS(count + 1);
        
        visit[i] = false;
    }
}

void startGame()
{
    int start_player = 1;
    int score = 0;
    bool base[4];
    bool curren_inning_end;
    

    for(int e=1; e<=N; e++)
    {
        int out_count = 0;
        bool base[4] = {false, false, false, false};
    
        while(out_count < 3)
        {
            int play = arr[e][order[start_player]];
    
            if(play == 0)
            {
                out_count++;
            }
            else if(play == 1)
            {
                for(int b=3;b>=1;b--)
                {
                    if(base[b])
                    {
                        if(b==3)
                            score++;
                        else
                            base[b+1]=true;
                        base[b]=false;
                    }
                }
                base[1]=true;
            }
            else if(play == 2)
            {
                for(int b=3;b>=1;b--)
                {
                    if(base[b])
                    {
                        if(b>=2)
                            score++;
                        else
                            base[b+2]=true;
                        base[b]=false;
                    }
                }
                base[2]=true;
            }
            else if(play == 3)
            {
                for(int b=3;b>=1;b--)
                {
                    if(base[b])
                    {
                        score++;
                        base[b]=false;
                    }
                }
                base[3]=true;
            }
            else if(play == 4)
            {
                for(int b=3;b>=1;b--)
                {
                    if(base[b])
                    {
                        score++;
                        base[b]=false;
                    }
                }
                score++;
            }
    
            start_player++;
            if(start_player==10)
                start_player=1;
        }
    }

    maxSore = max(maxSore, score);
}
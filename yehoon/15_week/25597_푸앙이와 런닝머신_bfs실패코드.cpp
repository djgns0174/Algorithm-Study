#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"

using namespace std;

int X, T;

struct func_arg
{
    int button_cnt;
    int time;
    int meter;
    int prev_button;
    vector<pair<int,int>> arr;
};


vector<func_arg> answer;

void func(func_arg arg)
{
    //test
    // cout << "button_cnt " << arg.button_cnt << endl;
    // cout << "time " << arg.time<<endl;
    // cout << "meter " << arg.meter << endl;
    // cout << "prev_button " << arg.prev_button << endl << endl;

    if(arg.meter == X)
    {
        if(arg.time <= T)
        {
            answer.push_back(arg);
            return;
        }

        else 
        {
            return;
        }
    }

    else if(arg.meter > X) return;

    else 
    {
        arg.time++;
        func_arg cp_arg1 = arg;
        cp_arg1.meter += 1;
        func_arg cp_arg4 = arg;
        cp_arg4.meter += 4;
        func_arg cp_arg8 = arg;
        cp_arg8.meter += 8;

        if(cp_arg1.prev_button != 1)
        {
            cp_arg1.arr.push_back({cp_arg1.time-1, 1});
            cp_arg1.prev_button = 1;
            cp_arg1.button_cnt++;
        }

        if(cp_arg4.prev_button != 4)
        {
            cp_arg4.arr.push_back({cp_arg4.time-1, 4});
            cp_arg4.prev_button = 4;
            cp_arg4.button_cnt++;
        }

        if(cp_arg8.prev_button != 8)
        {
            cp_arg8.arr.push_back({cp_arg8.time-1, 8});
            cp_arg8.prev_button = 8;
            cp_arg8.button_cnt++;
        }

        func(cp_arg1); func(cp_arg4); func(cp_arg8);
    }
}

int main(void)
{
    cin >> X >> T;

    // 시간이 미터보다 더 많다면 기다렸다가 초당 1미터
    if(X <= T)
    {
        cout << 1 << endl;
        cout << T - X << " " << 1 << endl;

        return 0;
    }

    queue<int> q;

    func_arg arg1;
    arg1.button_cnt = 1;
    arg1.time = 1;
    arg1.meter = 1; 
    arg1.arr.push_back({0,1});
    arg1.prev_button = 1;
    func(arg1);

    func_arg arg4;
    arg4.button_cnt = 1; 
    arg4.time = 1;
    arg4.meter = 4;
    arg4.arr.push_back({0,4});
    arg4.prev_button = 4;
    func(arg4);
    
    func_arg arg8;
    arg8.button_cnt = 1; 
    arg8.time = 1;
    arg8.meter = 8;
    arg8.arr.push_back({0,8});
    arg8.prev_button = 8;
    func(arg8);


    if(answer.empty())
    {
        cout << -1 << endl;
        return 0;
    }

    func_arg answer_arg = answer[0];
    for(func_arg arg : answer)
    {
        if(arg.button_cnt < answer_arg.button_cnt)
        {
            answer_arg = arg;
        }
    }
    int later = T - answer_arg.time;
    cout << answer_arg.button_cnt << endl;
    for(pair<int,int> p : answer_arg.arr)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
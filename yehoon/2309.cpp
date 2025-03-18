#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int arr[9] = {0,};

    //입력받기
    for(int i=0; i<9; i++){
        cin >> arr[i];
    }

    //아홉 난쟁이 합 구하기
    int sum = 0;
    for(int i=0; i<9; i++){
        sum += arr[i];
    }

    //핵심로직
    int tmp = sum - 100;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(arr[i]+arr[j] == tmp){
                arr[i] = 0;
                arr[j] = 0;
                //틀렸던 이유
                //break;

                //정답 정렬
                int size = sizeof(arr) / sizeof(arr[0]);
                sort(arr, arr+size);

                //정답 출력
                for(int i=2; i<9; i++){
                    cout << arr[i] << endl;
                }
                return 0;
            }
        }
    }

    // //정답 정렬
    // int size = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr+size);

    // //정답 출력
    // for(int i=2; i<9; i++){
    //     cout << arr[i] << endl;
    // }
    // return 0;
}
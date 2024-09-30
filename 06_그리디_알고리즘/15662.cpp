#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> list;


void LeftRotation(int n) {
    //반시계 회전
    char first = list[n][0];
    for(int i = 1; i < 8; i++) {
        list[n][i-1] = list[n][i];
    }
    list[n][7] = first;
}

void RightRotation(int n) {
    //시계 회전
    char last = list[n][7];
    for(int i = 6; i >= 0; i--) {
        list[n][i+1] = list[n][i];
    }
    list[n][0] = last;
}

int main() {
    //입력
    int T, K;
    cin >> T;
    
    list.resize(T);
    for(int i = 0; i < T; i++) {
        cin >> list[i];
    }
    
    cin >> K;
    
    for(int i = 0; i < K; i++) {
        int n, d;
        cin >> n >> d;
        n--;
        
        //회전방향 저장
        vector<int> isRotate(T, 0);
        isRotate[n] = d;
        
        //오른쪽 회전방향 확인
        for(int j = n; j < T-1; j++) {
            if(list[j][2] != list[j+1][6]) {
                isRotate[j+1] = -isRotate[j];    //옆 톱니바퀴는 반대방향으로 회전
            }
            else break;
        }
        
        //왼쪽 회전방향 확인
        for(int j = n; j > 0; j--) {
            if(list[j][6] != list[j-1][2]) {
                isRotate[j-1] = -isRotate[j];
            }
            else break;
        }
        
        //회전
        for(int i = 0; i < T; i++) {
            if(isRotate[i] == -1) {
                LeftRotation(i);
            }
            else if(isRotate[i] == 1) {
                RightRotation(i);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < T; i++) {
        if(list[i][0] == '1') {
            cnt++;
        }
    }
    
    //출력
    cout << cnt;
    
    return 0;
    
}
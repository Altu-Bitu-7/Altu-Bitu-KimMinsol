#include <iostream>
using namespace std;

int dir[12];  // 방향 
int len[12];  // 길이

int main() {
    // 입력
    int k;  
    cin >> k;

    for (int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
        dir[i + 6] = dir[i];  
        len[i + 6] = len[i]; 
    }

    int big_area = 0, small_area = 0;

    for (int i = 3; i < 12; i++) {
        if (dir[i] == dir[i - 2] && dir[i - 1] == dir[i - 3]) {
            // 큰 직사각형의 면적 계산
            big_area = len[i + 1] * len[i + 2];

            // 작은 직사각형의 면적 계산
            small_area = len[i - 1] * len[i - 2];
            break;
        }
    }

    // 출력
    cout << k * (big_area - small_area) << endl;

    return 0;
}

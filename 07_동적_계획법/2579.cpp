#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int score[301];  // 계단 점수
    int dp[301];     // 각 계단에서의 최대 점수 저장
    
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]);  //세번째 계단의 두가지 경우

    //네번째 계단부터 최대 점수 구하기
    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }

    cout << dp[n];
    
    return 0;
}

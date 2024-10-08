#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);   //수열 A
    vector<int> dp(N, 1);  //각 원소에서의 가장 긴 증가하는 부분 수열의 길이
    
    // 수열 입력
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //이전 원소보다 큰 경우 수열의 길이 저장
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 가장 긴 증가하는 부분 수열의 길이 구하기
    int result = *max_element(dp.begin(), dp.end()); 
    cout << result << '\n';
    
    return 0;
}

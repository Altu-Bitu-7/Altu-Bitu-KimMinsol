#include <iostream>
#include <vector>
using namespace std;

int main() {
    //입력
    int n;
    cin >> n;
    
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    //초기 속도 설정
    long long speed = nums[n - 1]; 
    
    //역방향 탐색
    for (int i = n-2; i >= 0; --i) {
        if (nums[i] > speed) {
            speed = nums[i]; 
        } else {
            if (speed % nums[i] != 0) {
                speed = (speed / nums[i] + 1) * nums[i]; 
            }
        }
    }
    
    //출력
    cout << speed;
    
    return 0;
}
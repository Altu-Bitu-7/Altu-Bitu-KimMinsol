#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int binarySearch(int left, int right, vector<int>& length) {
    int answer = right;
    
    while(left <= right) {
        int mid = (left + right)/2;
        int cnt = 1;    //블루레이 개수
        int current_sum = 0;
        
        for(int i = 0; i < n; i++){
            // 현재 강의를 추가했을 때 용량을 초과하면 새로운 블루레이
            if(current_sum + length[i] > mid) {
                cnt ++;
                current_sum = 0;
            }
            current_sum += length[i];
        }
        
        //개수가 m개 이하면 더 작은 값 탐색 
        if(cnt <= m) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid +1;
        }
    }
    return answer;
}

int main() {
    cin >> n >> m;
    
    vector<int> lecture(n);
    int sum = 0;
    int max_length = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> lecture[i];
        sum += lecture[i];
        max_length = max(max_length, lecture[i]);
    }

    
    //블루레이 크기의 최소값은 가장 긴 강의 길이
    //최대값은 모든 강의 길이의 합 
    cout << binarySearch(max_length, sum, lecture) << '\n';
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int binarySearch(int left, int right, vector<int>& length) {
    int snack = 0;
    
    while(left <= right) {
        int mid = (left + right)/2;
        int cnt = 0;    //mid길이로 나눠줄 수 있는 조카 수
        
        for(int i = 0; i < length.size(); i++){
            cnt += length[i]/mid;
        }
        if(cnt < m) {
            right = mid - 1;
        }
        else {
            snack = mid;
            left = mid +1;
        }
    }
    return snack;
}

int main() {
    cin >> m >> n;
    
    vector<int> length(n);
    for(int i = 0; i < n; i++) {
        cin >> length[i];
    }
    sort(length.begin(), length.end());
    
    cout << binarySearch(1, length[n-1], length) << '\n';
    
    return 0;
}

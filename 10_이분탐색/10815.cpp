#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lowerBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) { 
        int mid = (left + right) / 2; 
        if (arr[mid] >= target) { // target보다 크거나 같으면 왼쪽으로 이동
            right = mid - 1;
        } else { // target보다 작으면 오른쪽으로 이동
            left = mid + 1;
        }
    }
    return left;
}

int upperBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) { 
        int mid = (left + right) / 2; 
        if (arr[mid] <= target) { // target보다 작거나 같으면 오른쪽으로 이동
            left = mid + 1;
        } else { // target보다 크면 왼쪽으로 이동
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, input;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    while (m--) {
        cin >> input;
        cout << upperBound(0, n - 1, input, arr) - lowerBound(0, n - 1, input, arr) << ' ';
    }
    
    return 0;
}

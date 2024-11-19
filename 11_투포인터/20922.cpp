#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    vector<int> count(100001, 0); // 등장 횟수
    int max_length = 0;
    int start = 0, end = 0;

    while (end < N) {
        int cur = sequence[end];
        count[cur]++;

        // 등장 횟수가 K보다 크면 start를 오른쪽으로 이동
        while (count[cur] > K) {
            count[sequence[start]]--;
            start++;
        }

        max_length = max(max_length, end - start + 1);
        end++;
    }

    cout << max_length << '\n';
    return 0;
}

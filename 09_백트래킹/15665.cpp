#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> num;
vector<int> sequence;

void dfs(int cnt) {
    // 수열의 길이가 M이면 출력
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << sequence[i] << " ";
        }
        cout << '\n';
        return;
    }
    int prev = -1; // 바로 직전에 골랐던 수 저장

    for (int i = 0; i < N; i++) {
        if(prev != num[i]) {
            sequence[cnt] = num[i];
            prev = num[i];
            dfs(cnt + 1);
        }
    }
}

int main() {
    // 입력
    cin >> N >> M;
    num.resize(N);
    sequence.resize(M);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // 사전 순으로 정렬
    sort(num.begin(), num.end());
    
    dfs(0);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int N;
vector<int> numbers;      
int operators[4];         // 연산자 (덧셈, 뺄셈, 곱셈, 나눗셈)
int maxResult = -1000000000; 
int minResult = 1000000000;   

void dfs(int idx, int currentResult, int add, int sub, int mul, int div) {
    // 모든 수에 대해 연산이 끝났을 때
    if (idx == N) {
        maxResult = max(maxResult, currentResult); // 최댓값 갱신
        minResult = min(minResult, currentResult); // 최솟값 갱신
        return;
    }

    // 각 연산자 사용
    if (add > 0) {
        dfs(idx + 1, currentResult + numbers[idx], add - 1, sub, mul, div);
    }
    if (sub > 0) {
        dfs(idx + 1, currentResult - numbers[idx], add, sub - 1, mul, div);
    }
    if (mul > 0) {
        dfs(idx + 1, currentResult * numbers[idx], add, sub, mul - 1, div);
    }
    if (div > 0) {
        dfs(idx + 1, currentResult / numbers[idx], add, sub, mul, div - 1);
    }
}

int main() {
    // 입력
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i]; // +, -, *, / 연산자의 개수
    }

    // DFS를 사용하여 모든 경우 탐색
    dfs(1, numbers[0], operators[0], operators[1], operators[2], operators[3]);

    // 출력
    cout << maxResult << endl;
    cout << minResult << endl;

    return 0;
}

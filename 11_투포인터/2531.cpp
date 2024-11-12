#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max_sushi = 0;
    for (int i = 0; i < N; i++) {
        int eat_sushi = 1; // 쿠폰으로 추가한 초밥
        vector<int> check(d + 1, 0);
        check[c] = 1; // 쿠폰 초밥을 미리 포함

        for (int j = i; j < i + k; j++) {
            int sushi = arr[j % N]; // 원형 벨트

            if (check[sushi] == 0) {    // 새로 먹은 초밥 종류 추가
                eat_sushi++;
            }
            check[sushi]++;
        }

        max_sushi = max(max_sushi, eat_sushi);
    }

    cout << max_sushi << endl;
    return 0;
}

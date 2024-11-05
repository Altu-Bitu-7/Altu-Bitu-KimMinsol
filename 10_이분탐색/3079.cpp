#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binarySearch(ll left, ll right, const vector<ll>& times, ll m) {
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_people = 0;

        for (ll time : times) {
            total_people += mid / time;  //각 심사대에서 mid 시간 내에 처리할 수 있는 인원 수
        }

        if (total_people >= m) {  //모든 인원을 처리할 수 있으면 시간을 줄이기
            answer = mid;
            right = mid - 1;
        } else {  //처리할 수 없으면 시간을 늘리기
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> times(n);
    ll max_time = 0;

    for (int i = 0; i < n; i++) {
        cin >> times[i];
        max_time = max(max_time, times[i]);
    }

    //최솟값: 1분, 최댓값: 가장 긴 심사 시간 * 총 인원 수
    ll result = binarySearch(1, max_time * m, times, m);

    cout << result << '\n';

    return 0;
}

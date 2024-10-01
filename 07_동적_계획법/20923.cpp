#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dodo_deck, suyeon_deck;
    deque<int> dodo_ground, suyeon_ground;

    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        dodo_deck.push_front(d);
        suyeon_deck.push_front(s);
    }

    bool dodo_turn = true; 

    for (int turn = 0; turn < M; turn++) {
        // 1. 도도의 차례인지 수연의 차례인지 확인
        if (dodo_turn) {
            // 도도 차례
            if (!dodo_deck.empty()) {
                dodo_ground.push_front(dodo_deck.front()); // 도도의 그라운드에 카드 추가
                dodo_deck.pop_front(); // 도도의 덱에서 카드 제거
            }
        } else {
            // 수연 차례
            if (!suyeon_deck.empty()) {
                suyeon_ground.push_front(suyeon_deck.front()); // 수연의 그라운드에 카드 추가
                suyeon_deck.pop_front(); // 수연의 덱에서 카드 제거
            }
        }

        // 2. 종 치는 조건 확인 (도도 먼저 확인, 그 다음 수연)
        if (!dodo_ground.empty() && !suyeon_ground.empty()) {
            if (dodo_ground.front() == 5 || suyeon_ground.front() == 5) {
                while (!suyeon_ground.empty()) {
                    dodo_deck.push_back(suyeon_ground.back());
                    suyeon_ground.pop_back();
                }
                while (!dodo_ground.empty()) {
                    dodo_deck.push_back(dodo_ground.back());
                    dodo_ground.pop_back();
                }
            }
            // 수연이가 종을 칠 조건: 도도 + 수연의 카드 합이 5일 경우
            else if (dodo_ground.front() + suyeon_ground.front() == 5) {
                while (!dodo_ground.empty()) {
                    suyeon_deck.push_back(dodo_ground.back());
                    dodo_ground.pop_back();
                }
                while (!suyeon_ground.empty()) {
                    suyeon_deck.push_back(suyeon_ground.back());
                    suyeon_ground.pop_back();
                }
            }
        }

        // 3. 한명의 덱이 비면 게임 종료
        if (dodo_deck.empty()) {
            cout << "su" << endl;
            return 0;
        } else if (suyeon_deck.empty()) {
            cout << "do" << endl;
            return 0;
        }

        dodo_turn = !dodo_turn;
    }

    // 4. M번 끝난 후
    if (dodo_deck.size() > suyeon_deck.size()) {
        cout << "do" << endl;
    } else if (dodo_deck.size() < suyeon_deck.size()) {
        cout << "su" << endl;
    } else {
        cout << "dosu" << endl;
    }

    return 0;
}

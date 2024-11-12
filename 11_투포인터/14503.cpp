#include <iostream>
#include <vector>

using namespace std;

const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북, 동, 남, 서

int N, M;
vector<vector<int>> room;   // 0: 청소 필요, 1: 벽, 2: 청소됨

bool validatePosition(int x, int y) {   // 방의 범위 내에 있는지 확인
    return !(x < 0 || x >= N || y < 0 || y >= M);
}

bool notClean(int x, int y) { // 청소할 칸이 있는지 확인
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (validatePosition(dx, dy) && room[dx][dy] == 0) {
            return true;
        }
    }
    return false;
}

int cleanRoom(int x, int y, int direction) {
    int count = 0;
    while (true) {
        if (room[x][y] == 0) {  // 청소되지 않은 칸이면 청소(2)
            count++;
            room[x][y] = 2; 
        }

        if (notClean(x, y)) {   // 주변에 청소할 칸 있는지 탐색
            for (int i = 1; i <= 4; i++) {
                int index = (direction - i + 4) % 4; // 반시계 방향으로 회전
                int dx = x + dir[index][0];
                int dy = y + dir[index][1];

                if (!validatePosition(dx, dy)) continue;

                if (room[dx][dy] == 0) {
                    direction = index;
                    x = dx;
                    y = dy;
                    break;
                }
            }
        } else {
            int back_x = x - dir[direction][0];
            int back_y = y - dir[direction][1];

            if (!validatePosition(back_x, back_y) || room[back_x][back_y] == 1) {
                return count;
            }
            x = back_x;
            y = back_y;
        }
    }
}

int main() {
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;

    room.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int answer = cleanRoom(r, c, d);
    cout << answer << '\n';

    return 0;
}

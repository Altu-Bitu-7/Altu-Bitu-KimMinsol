#include <iostream>
using namespace std;

const int N = 19;

//방향 배열 (오른쪽, 아래, 오른쪽 아래 대각선, 왼쪽아래 대각선)
int dx[4] = {1, 0, 1, -1};
int dy[4] = {0, 1, 1, 1};

int board[N][N];

//연속된 바둑알 확인
bool check(int x, int y, int color) {
    for (int dir = 0; dir < 4; ++dir) {
        int cnt = 1;
        int nx = x, ny = y;

        //반대방향으로 체크해서 연속된 바둑알이 없는지 확인
        int prev_x = x - dx[dir], prev_y = y - dy[dir];
        if (prev_x >= 0 && prev_y >= 0 && prev_x < N && prev_y < N && board[prev_x][prev_y] == color) {
            continue;
        }

        //직선상에 연속된 바둑알 개수 세기
        while (true) {
            nx += dx[dir];
            ny += dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && board[nx][ny] == color) {
                cnt++;
            } else {
                break;
            }
        }

        if (cnt == 5) {
            return true;
        }
    }
    return false;
}

int main() {
    //입력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    //바둑판 확인
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                int color = board[i][j];

                if (check(i, j, color)) {
                    cout << color << '\n';  
                    cout << i + 1 << ' ' << j + 1 << '\n';  
                    return 0;
                }
            }
        }
    }

    cout << 0 << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k, l;
vector<vector<int>> map;                //게임 보드
deque<pair<int, int>> snake;            //뱀의 위치
vector<pair<int, char>> directions;     //방향 정보
int dx[] = {0, 1, 0, -1};               //동, 남, 서, 북
int dy[] = {1, 0, -1, 0};

bool isFinish(int nx, int ny) {
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {   //벽에 부딪힘
        return true;
    }
    for (int i = 0; i < snake.size(); i++) {
        if (nx == snake[i].first && ny == snake[i].second) {    //자기자신과 충돌
            return true;
        }
    }
    return false;
}

int solve() {
    int time = 0;  
    int d = 0;      //현재 방향 (0,1,2,3: 동,남,서,북)
    int cx = 0, cy = 0;  //현재 머리 위치
    int dirIndex = 0;    
    snake.push_back({0, 0}); 

    while (true) {
        time++;
        // 다음 위치 계산
        int nx = cx + dx[d];
        int ny = cy + dy[d];

        if (isFinish(nx, ny)) {
            break;
        }

        if (map[nx][ny] == 1) { //사과가 있는 경우
            map[nx][ny] = 0; 
            snake.push_front({nx, ny});
        } else {
            snake.push_front({nx, ny}); //사과가 없는 경우
            snake.pop_back(); //꼬리를 줄임
        }

        if (dirIndex < directions.size() && time == directions[dirIndex].first) {
            char turn = directions[dirIndex].second;
            if (turn == 'D') {
                d = (d + 1) % 4; //오른쪽 회전
            } else {
                d = (d + 3) % 4; //왼쪽 회전
            }
            dirIndex++;
        }

        //현재 위치 업데이트
        cx = nx;
        cy = ny;
    }

    return time;
}

int main() {
    cin >> n;
    cin >> k;

    map.resize(n, vector<int>(n, 0));

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1; 
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        directions.emplace_back(x, c);
    }

    int result = solve();
    cout << result << '\n';

    return 0;
}

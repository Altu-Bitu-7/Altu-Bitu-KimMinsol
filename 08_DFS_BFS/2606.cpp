#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;  
vector<int> graph[MAX + 1];  // 네트워크 연결 정보 저장
bool visited[MAX + 1];  // 방문 여부

//BFS를 사용하여 1번 컴퓨터와 연결된 컴퓨터 탐색
int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;  
    int count = 0;  // 감염된 컴퓨터 수

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true; 
                q.push(next);
                count++;  
            }
        }
    }

    return count; 
}

int main() {
    int n, m;  
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }

    // 1번 컴퓨터에서 감염된 컴퓨터 계산
    int result = bfs(1);

    cout << result << endl;

    return 0;
}

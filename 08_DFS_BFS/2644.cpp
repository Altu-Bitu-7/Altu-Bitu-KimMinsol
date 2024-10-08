#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;  
vector<int> graph[MAX + 1];  // 각 사람의 부모-자식 관계
bool visited[MAX + 1];  // 방문 여부 확인하는 배열
int dist[MAX + 1];  // 촌수 저장 배열

// BFS를 사용하여 두 사람의 촌수를 계산
int calculate_relation(int start, int target) {
    queue<int> q;
    visited[start] = true;  
    q.push(start);  

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) {
            return dist[current];
        }

        // 현재 사람과 연결된 사람들 탐색
        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;  //방문 표시
                dist[next] = dist[current] + 1;  // 촌수 +1
                q.push(next);  //다음 사람 추가
            }
        }
    }

    return -1; 
}

int main() {
    int n; 
    cin >> n;

    int p1, p2; 
    cin >> p1 >> p2;

    int m;  
    cin >> m;

    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent); 
    }

    int result = calculate_relation(p1, p2);

    //출력
    cout << result << endl;

    return 0;
}

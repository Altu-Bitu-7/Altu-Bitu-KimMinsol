#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001; 
vector<int> tree[MAX];
int subSize[MAX];  
bool visited[MAX];

//서브트리 크기 계산
int count(int node) {
    visited[node] = true;
    subSize[node] = 1; //자기 자신을 포함
    for (int child : tree[node]) {
        if (!visited[child]) {
            subSize[node] += count(child); //자식 노드의 서브트리 크기 추가
        }
    }
    return subSize[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q; 
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    count(r);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << subSize[u] << "\n"; 
    }

    return 0;
}

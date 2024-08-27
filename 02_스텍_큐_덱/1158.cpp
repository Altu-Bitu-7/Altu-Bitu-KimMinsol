#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;

    for(int i = 1; i <= n; i++) { //n까지의 정수를 큐에 삽입
        q.push(i);
    }

    cout << "<";

    while(n--) {
        for(int i = 1; i < k; i++) { //k-1번째까지의 원소를 큐의 뒤에 push, 앞에 있는 원소들은 pop하면 큐의 맨앞에는 k번째 원소가 존재하게 됨.
            q.push(q.front());
            q.pop();
        }
        cout << q.front();  //k번째 원소인 q.front()를 출력한 뒤 pop
        q.pop();

        if(n > 0) {
            cout << ", ";
        }
    }
    cout << ">\n"; //큐에 원소가 하나 남아있을 때 출력
    return 0;
}
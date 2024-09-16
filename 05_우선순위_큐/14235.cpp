#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;  
    priority_queue<int> q;  

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;  

        if (a == 0) {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.top() << endl;
                q.pop();
            }
        } else {
            for (int j = 0; j < a; ++j) {
                int gift;
                cin >> gift;
                q.push(gift);  
            }
        }
    }

    return 0;
}
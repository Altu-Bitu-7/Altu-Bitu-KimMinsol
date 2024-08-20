#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    int count;
    string input;
    set<string> s;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        s.insert(input);
    }

    for(int i = 0; i < m; i++) {
        cin >> input;
        count += s.count(input);
    }

    cout << count;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string serial) {
    int sum = 0;
    for(int i = 0; i < serial.size(); i++) {
        if(isdigit(serial[i])) {
            sum += serial[i] - '0';
        }
    }
    return sum;
}

bool cmp(const string& s1, const string& s2) {
    if(s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    if(sum(s1) != sum(s2)) {
        return sum(s1) < sum(s2);
    }
    return s1 < s2;

}

int main() {
    int n;
    cin >> n;
    vector<string> serial_number(n);

    for(int i = 0; i < n; i++) {
        cin >> serial_number[i];
    }

    sort(serial_number.begin(), serial_number.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << serial_number[i] << '\n';
    }
    return 0;

}
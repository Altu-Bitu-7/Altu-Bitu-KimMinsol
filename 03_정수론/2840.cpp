#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<char> v(n, '?');

    int curr = 0;   //현재 원소의 인덱스
    bool valid = true;  //벡터가 유효한지

    for(int i = 0; i < k; i++) {
        int s;
        char ch;
        cin >> s >> ch;

        int newIndex = (curr + s) % n;  //새로운 원소의 인덱스

        if (v[newIndex] != '?' && v[newIndex] != ch) {
            valid = false;  // Conflict detected
            break;
        }

        if(v[newIndex] == '?' && find(v.begin(), v.end(), ch) != v.end()){ //자리가 비어있으면서 vector 내에 해당 문자가 존재하면 오류 (문자가 중복될 수 없음)
            valid = false;
            break;
        }

        v[newIndex] = ch; 
        curr = newIndex;
    }

    if(!valid) {
        cout << '!' << '\n';
    }
    else {
        for(int i = 0; i < n; i++) {
            cout << v[(curr - i + n) % n];
        }
        cout << '\n';
    }

    return 0;

}
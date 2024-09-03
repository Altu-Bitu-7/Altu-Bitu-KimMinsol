#include <iostream>
#include <algorithm>
using namespace std;

//최대공약수 구하기
int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}


int main() {
    int a1, a2, b1, b2;
    int c1, c2;

    cin >> a1 >> a2;
    cin >> b1 >> b2;

    //분수 더하기
    c1 = a1 * b2 + a2 * b1;
    c2 = a2 * b2;

    //최대공약수
    int gcd = getGcdRecur(c1, c2);

    //최대공약수로 나누기
    if(gcd != 1) {
        c1 = c1 / gcd;
        c2 = c2 / gcd;
    }

    cout << c1 << ' ' << c2;
    return 0;

}
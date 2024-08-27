#include <iostream>
#include <string>
#include <stack>

using namespace std;

string addNum(string a, string b){
    stack<int> s1, s2, s3;
    string result = "";

    for(int i = 0; i < a.size(); i++) { //첫번째 정수를 스택1에 push
        int anum = a[i] - '0';
        s1.push(anum);
    }

    for(int i = 0; i < b.size(); i++) { //두번째 정수를 스택2에 push
        int bnum = b[i] - '0';
        s2.push(bnum);
    }

    int plus = 0;

    while(!s1.empty() || !s2.empty() || plus) {
        int num1 = 0, num2 = 0;
        if(!s1.empty()) {
            num1 = s1.top();
            s1.pop();
        }
        if(!s2.empty()) {
            num2 = s2.top();
            s2.pop();
        }

        //스택의 top을 뽑아서 더하고, 10으로 나눈 나머지를 스택3에 push함.
        //10으로 나눈 몫을 plus가 하고 다음 반복에서 더함.
        int sum = num1 + num2 + plus;
        s3.push(sum % 10);
        plus = sum / 10;
    }

    while(!s3.empty()) {
        result += to_string(s3.top());
        s3.pop();
    }
    return result;
}

int main() {
    string a, b;    //매우 큰 수는 int로 받을 수 없으므로 string으로 받는다.
    cin >> a >> b;

    string res = addNum(a, b);

    cout << res;

    return 0;
}
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string& str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        char c = str[i];    

        if(c == '(' || c == '[') {  //문자가 ( 또는 [이면 스택에 push
            s.push(c);
        }
        else if (c == ')' || c == ']') {    //) 또는 ]인 경우
            if(s.empty()) return false;     //스택이 비어있으면 균형X
            char top = s.top();
            s.pop();

            //균형이 맞지 않는 경우
            if((c == ')' && top != '(') || (c == ']' && top != '[')) {
                return false;   
            }
        }
    }
    return s.empty();
}

int main() {
    while(true) {
        string line;
        getline(cin, line);

        if(line == ".") break;

        if (isBalanced(line)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

return 0;
}
#include <iostream>
#include <string>

using namespace std;

int findNum(int n) {
    //666을 포함하는 숫자이면 count+1
    int count = 0;
    int num = 666;
    
    while(true) {
        string s_num = to_string(num);
        if(s_num.find("666") != string::npos) {
            count++;
        }
        
        if(count == n) {
            return num;
        }
        
        num++;
    }

}

int main() {
    int N;
    cin >> N;
    
    cout << findNum(N);
    return 0;
    
}
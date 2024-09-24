#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alphabet[26] = {0};

int main() {
    //입력
    string str;
    cin >> str;
    
    //각 알파벳의 개수를 alphabet배열에 저장
    for(int i = 0; i < str.length(); i++) {
        alphabet[str[i]-'A']++;
    }
    
    int odd = 0;
    //홀수개 알파벳 count
    for(int i = 0; i < 26; i++) {
        if(alphabet[i]%2 != 0) {
            odd++;
        }
    }
    
    string ans;
    char oddChar;
    
    if(odd > 1) {
        cout << "I'm Sorry Hansoo";
    }
    else {
        //절반만큼을 ans 문자열에 추가
        for(int i = 0; i < 26; i++) {
            if(alphabet[i] != 0) {
                ans.append(alphabet[i]/2, i+'A');
            }
        }
        //홀수 알파벳 저장
        for(int i = 0; i < 26; i++) {
            if(alphabet[i]%2 != 0) {
                oddChar = i+'A';
            }
        }
        
        string temp = ans;
        reverse(temp.begin(), temp.end());
        if(odd == 1) {
            ans += oddChar;
        }
        ans += temp;

        cout << ans;
        
    }
    
    return 0;
}

// 한 종류의 문자가 짝수개여야함. 홀수개인 문자는 1개 이하여야 한다.
// 예: AABBC는 팰린드롬 가능, AABBCD는 팰린드롬 불가능 -> '홀수'개인 문자가 두개
// 1)문자의 개수를 count하고 alphabet[26] 배열에 개수 저장
// 2)홀수개인 알파벳이 두개 이상이면 에러
// 3)알파벳의 절반 개수만큼 붙여서 반을 만들고
// 홀수 1개 존재하면 해당 홀수개인 알파벳을 중간에 배치하고
// 앞쪽 반을 뒤집어서 그 뒤에 붙인다.

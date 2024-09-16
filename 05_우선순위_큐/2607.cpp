#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, similar = 0;
    cin >> n;
    cin.get(); 

    //단어 입력
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        getline(cin, words[i]);
    }

    for (int i = 1; i < n; i++) {
        //첫번째 단어와 현재 단어의 문자 빈도 배열
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int count = 0;

        //문자 빈도 계산
        for (char ch : words[0]) freq1[ch - 'A']++; //첫번째 단어
        for (char ch : words[i]) freq2[ch - 'A']++; //현재 단어

        //같은 문자의 개수 세기
        for (int j = 0; j < 26; j++) {
            count += min(freq1[j], freq2[j]);
        }

        //길이와 일치하는 문자 수 비교
        int len1 = words[0].size();
        int len2 = words[i].size();
        if ((len1 == count && len2 == count) ||
            (len1 == count && len2 == count + 1) ||
            (len1 == count + 1 && len2 == count) ||
            (len1 == count + 1 && len2 == count + 1))
        {
            similar++;
        }
    }
    cout << similar << '\n';
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int alphabet[26] = {0}; // 알파벳 빈도수를 저장할 배열
    int maxCount = 0;
    int maxIndex = 0;
    bool duplicate = false;

    for (int i = 0; i < s.length(); i++) {
        // 모든 문자를 대문자로 변환 (소문자라면 'a'를 빼서 0~25 인덱스 생성)
        char c = toupper(s[i]);
        alphabet[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > maxCount) {
            maxCount = alphabet[i];
            maxIndex = i;
            duplicate = false; // 새로운 최댓값이 나오면 중복 상태 해제
        } 
        else if (alphabet[i] == maxCount && maxCount != 0) {
            duplicate = true; // 최댓값이 이미 있는데 또 같은 값이 나오면 중복
        }
    }

    if (duplicate) {
        cout << "?" << endl;
    } else {
        // 인덱스를 다시 문자로 변환 (0 -> 'A')
        cout << (char)(maxIndex + 'A') << endl;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    int count = 0;

    // cin은 공백(스페이스, 탭, 엔터)을 기준으로 입력을 끊어서 읽습니다.
    // 더 이상 읽을 단어가 없을 때까지 반복합니다.
    while (cin >> word) {
        count++;
    }

    cout << count << endl;

    return 0;
}

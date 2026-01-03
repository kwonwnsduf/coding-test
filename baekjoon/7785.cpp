#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // 1. 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;

    for (int i = 0; i < n; i++) {
        string name, action;
        cin >> name >> action;

        if (action == "enter") {
            s.insert(name); // 회사 들어옴
        } else {
            s.erase(name);  // 회사 나감
        }
    }

    // 2. 역반복자를 사용하여 사전 순의 역순으로 출력
    // s.rbegin()은 맨 뒤(가장 큰 값)부터 시작합니다.
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << "\n";
    }

    return 0;
}

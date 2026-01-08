#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<string> dancing;
    // 처음에는 총총이만 춤을 추고 있음
    dancing.insert("ChongChong");

    for (int i = 0; i < N; i++) {
        string p1, p2;
        cin >> p1 >> p2;

        // 만난 사람 중 한 명이라도 춤을 추고 있다면
        if (dancing.count(p1) || dancing.count(p2)) {
            dancing.insert(p1);
            dancing.insert(p2);
        }
    }

    // 최종적으로 춤을 추는 사람의 수 출력
    cout << dancing.size() << endl;

    return 0;
}

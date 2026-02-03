#include <iostream>
#include <queue> // priority_queue 포함
#include <vector>

using namespace std;

int main() {
    // 입출력 가속
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // ★ 최소 힙 선언 방식 ★
    // 자료형: int
    // 구현체: vector<int>
    // 비교함수: greater<int> (큰 게 뒤로 가라 -> 작은 게 앞으로 온다)
    priority_queue<int, vector<int>, greater<int>> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                // 힙의 맨 위(가장 작은 값) 출력 후 제거
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            // 숫자 추가
            pq.push(x);
        }
    }

    return 0;
}

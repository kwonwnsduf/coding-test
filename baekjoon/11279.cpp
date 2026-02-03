#include <iostream>
#include <queue> // priority_queue 사용

using namespace std;

int main() {
    // 1. 입출력 속도 향상 (필수!)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // C++의 priority_queue는 기본적으로 '최대 힙'입니다.
    priority_queue<int> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            // 2. x가 0이면 가장 큰 값 출력 후 제거
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n"; // 최댓값 확인
                pq.pop();                // 최댓값 제거
            }
        } else {
            // 3. x가 자연수면 힙에 추가
            pq.push(x);
        }
    }

    return 0;
}

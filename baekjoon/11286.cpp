#include <iostream>
#include <queue>
#include <vector>
#include <cmath> // abs() 사용

using namespace std;

// 1. 나만의 정렬 기준 구조체 정의
struct compare {
    bool operator()(int a, int b) {
        // 절댓값이 같다면 실제 값을 비교
        if (abs(a) == abs(b)) {
            return a > b; // 더 큰 숫자가 뒤로 가게 (작은 음수가 위로)
        }
        // 절댓값이 다르다면 절댓값을 비교
        return abs(a) > abs(b); // 절댓값이 더 큰 숫자가 뒤로 가게 (작은 절댓값이 위로)
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 2. priority_queue 선언 (커스텀 비교 함수 적용)
    priority_queue<int, vector<int>, compare> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}

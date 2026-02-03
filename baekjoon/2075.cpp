#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 가장 작은 값을 계속 뽑아내기 위해 최소 힙 사용
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N * N; i++) {
        int temp;
        cin >> temp;

        pq.push(temp);

        // 힙의 크기를 N개로 유지하는 것이 핵심!
        // N개보다 많아지면 가장 작은 값을 버려서 상위 N개만 남김
        if (pq.size() > N) {
            pq.pop();
        }
    }

    // 모든 숫자를 처리한 후, 최소 힙의 top은 "상위 N개 중 가장 작은 수"
    // 즉, 전체에서 N번째로 큰 수가 됨
    cout << pq.top() << "\n";

    return 0;
}

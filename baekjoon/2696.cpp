#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int M;
    cin >> M;

    priority_queue<int> max_pq; // 왼쪽 팀 (최대 힙)
    priority_queue<int, vector<int>, greater<int>> min_pq; // 오른쪽 팀 (최소 힙)
    vector<int> medians;

    cout << (M + 1) / 2 << "\n"; // 출력할 중앙값의 총 개수

    for (int i = 1; i <= M; i++) {
        int x;
        cin >> x;

        // 1. 번갈아가며 삽입
        if (max_pq.size() == min_pq.size()) max_pq.push(x);
        else min_pq.push(x);

        // 2. 균형 맞추기 (왼쪽 대장이 더 크면 swap)
        if (!max_pq.empty() && !min_pq.empty()) {
            if (max_pq.top() > min_pq.top()) {
                int max_val = max_pq.top();
                int min_val = min_pq.top();
                max_pq.pop(); min_pq.pop();
                max_pq.push(min_val);
                min_pq.push(max_val);
            }
        }

        // 3. 홀수 번째마다 중앙값 저장
        if (i % 2 != 0) {
            medians.push_back(max_pq.top());
        }
    }

    // 4. 형식에 맞춰 출력 (10개마다 줄바꿈)
    for (int i = 0; i < medians.size(); i++) {
        cout << medians[i] << " ";
        if ((i + 1) % 10 == 0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

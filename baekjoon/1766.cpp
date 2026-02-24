#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    // 1. 그래프 및 진입 차수 설정
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // 2. 우선순위 큐(최소 힙) 정의
    // 큰 값이 기본이므로 greater<int>를 사용해 작은 값이 먼저 나오게 함
    priority_queue<int, vector<int>, greater<int>> pq;

    // 3. 진입 차수가 0인 문제를 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    // 4. 위상 정렬 시작
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        cout << curr << " ";

        for (int next : adj[curr]) {
            indegree[next]--;
            // 새롭게 풀 수 있게 된 문제를 큐에 추가
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // 인접 리스트
    vector<int> in_degree(N + 1, 0); // 진입 차수 배열

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B); // A가 B 앞에 서야 함
        in_degree[B]++;      // B의 진입 차수 증가
    }

    queue<int> q;
    // 1. 진입 차수가 0인 노드를 큐에 삽입 [00:15:02]
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // 2. 위상 정렬 수행 [00:15:30]
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " "; // 결과 출력

        for (int next : adj[curr]) {
            in_degree[next]--; // 연결된 노드의 진입 차수 감소 
            if (in_degree[next] == 0) {
                q.push(next); // 진입 차수가 0이 되면 큐에 삽입
            }
        }
    }

    return 0;
}

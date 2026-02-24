#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int adj[501][501];
int indegree[501];
int team[501];

void solve() {
    int n, m;
    cin >> n;
    
    // 초기화
    for (int i = 1; i <= n; i++) {
        indegree[i] = 0;
        for (int j = 1; j <= n; j++) adj[i][j] = 0;
    }

    for (int i = 0; i < n; i++) cin >> team[i];

    // 1. 작년 순위 기반 그래프 생성 (i등 -> j등)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            adj[team[i]][team[j]] = 1;
            indegree[team[j]]++;
        }
    }

    // 2. 바뀐 순위 적용
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (adj[u][v]) { // u -> v 였다면 v -> u로
            adj[u][v] = 0;
            adj[v][u] = 1;
            indegree[v]--;
            indegree[u]++;
        } else { // v -> u 였다면 u -> v로
            adj[v][u] = 0;
            adj[u][v] = 1;
            indegree[u]--;
            indegree[v]++;
        }
    }

    // 3. 위상 정렬
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    bool certain = true;

    for (int i = 0; i < n; i++) {
        if (q.empty()) { // 사이클 발생
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (q.size() > 1) certain = false; // 여러 경로 가능 (사실 이 문제에선 드문 케이스)

        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next = 1; next <= n; next++) {
            if (adj[curr][next]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
    }

    if (!certain) {
        cout << "?" << endl;
    } else {
        for (int i = 0; i < n; i++) cout << result[i] << (i == n - 1 ? "" : " ");
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

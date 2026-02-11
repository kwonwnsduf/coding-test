#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> adj[20001];
int visited[20001]; // 0: 미방문, 1: 빨강, 2: 파랑

bool isBipartite(int start, int V) {
    queue<int> q;
    q.push(start);
    visited[start] = 1; // 시작은 빨간색

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            // 아직 방문 안 했다면 반대 색으로 칠함
            if (visited[next] == 0) {
                visited[next] = (visited[cur] == 1) ? 2 : 1;
                q.push(next);
            }
            // 이미 방문했는데 나랑 색이 같다면? 이분 그래프 아님!
            else if (visited[next] == visited[cur]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int V, E;
    cin >> V >> E;

    // 초기화
    for (int i = 1; i <= V; i++) {
        adj[i].clear();
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = true;
    for (int i = 1; i <= V; i++) {
        if (visited[i] == 0) {
            if (!isBipartite(i, V)) {
                ans = false;
                break;
            }
        }
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    bool negative_cycle = false;

    // N번 반복 (마지막 N번째에 갱신되면 사이클이 있는 것)
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].cost;

            // 아직 시작점에서 도달할 수 없는 노드는 건너뜀
            if (dist[u] == INF) continue;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                // N번째 반복에서도 갱신이 일어난다면 음의 사이클 존재
                if (i == N) negative_cycle = true;
            }
        }
    }

    if (negative_cycle) {
        cout << -1 << "\n";
    } else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}

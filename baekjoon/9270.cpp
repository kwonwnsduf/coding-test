#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 표준 다익스트라 함수
vector<int> dijkstra(int start, int n, const vector<pair<int, int>> adj[]) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < d) continue;

        for (auto& edge : adj[curr]) {
            int next = edge.first;
            int weight = edge.second;
            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<pair<int, int>> adj[2001];
    int gh_weight = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if ((u == g && v == h) || (u == h && v == g)) gh_weight = w;
    }

    vector<int> targets(t);
    for (int i = 0; i < t; i++) cin >> targets[i];

    // 1. s, g, h 각각에서 출발하는 최단 거리 계산
    vector<int> distS = dijkstra(s, n, adj);
    vector<int> distG = dijkstra(g, n, adj);
    vector<int> distH = dijkstra(h, n, adj);

    vector<int> result;
    for (int dest : targets) {
        // 경로 1: s -> g -> h -> dest
        long long path1 = (long long)distS[g] + gh_weight + distH[dest];
        // 경로 2: s -> h -> g -> dest
        long long path2 = (long long)distS[h] + gh_weight + distG[dest];
        
        long long min_path = min(path1, path2);

        // 만약 반드시 거쳐간 경로의 합이 실제 최단 거리와 같다면 정답
        if (min_path != INF && min_path == distS[dest]) {
            result.push_back(dest);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

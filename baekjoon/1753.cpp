#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대를 나타내는 값

int main() {
    // 입출력 성능 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<pair<int, int>> adj[20001]; // 인접 리스트 (연결된 정점, 가중치)
    vector<int> dist(V + 1, INF);     // 최단 거리 배열

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // 우선순위 큐: {거리, 정점 번호}, 거리가 짧은 것이 top으로 오게 설정
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점 설정
    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        // 이미 처리된 거리가 더 짧다면 무시
        if (dist[curr] < d) continue;

        for (auto& edge : adj[curr]) {
            int next = edge.first;
            int weight = edge.second;

            // 거쳐서 가는 것이 더 빠를 경우 갱신
            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // 출력
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}

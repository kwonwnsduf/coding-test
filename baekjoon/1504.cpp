#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e8; // 경로가 없을 때를 대비해 적당히 큰 값 설정
int N, E;
vector<pair<int, int>> adj[801];

// 다익스트라 함수: 시작점(start)에서 다른 모든 점까지의 거리 반환
vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // 무방향 그래프
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 3번의 다익스트라 실행
    vector<int> distFrom1 = dijkstra(1);
    vector<int> distFromV1 = dijkstra(v1);
    vector<int> distFromV2 = dijkstra(v2);

    // 경로 1: 1 -> v1 -> v2 -> N
    long long path1 = (long long)distFrom1[v1] + distFromV1[v2] + distFromV2[N];
    
    // 경로 2: 1 -> v2 -> v1 -> N
    long long path2 = (long long)distFrom1[v2] + distFromV2[v1] + distFromV1[N];

    long long result = min(path1, path2);

    if (result >= INF) cout << -1;
    else cout << result;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;
int dist[401][401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    // 1. 초기화 (모두 INF로)
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
        }
    }

    // 2. 간선 정보
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    // 3. 플로이드-워셜 (k -> i -> j)
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 4. 사이클 최솟값 찾기 (dist[i][i] 확인)
    int min_cycle = INF;
    for (int i = 1; i <= V; i++) {
        min_cycle = min(min_cycle, dist[i][i]);
    }

    // 5. 결과 출력
    if (min_cycle == INF) cout << -1;
    else cout << min_cycle;

    return 0;
}

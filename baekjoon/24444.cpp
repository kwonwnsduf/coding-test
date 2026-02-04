#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // BFS를 위한 큐 헤더

using namespace std;

vector<int> adj[100001];
int order[100001];
bool visited[100001];
int cnt = 0;

void bfs(int start) {
    queue<int> q;
    
    // 1. 시작 노드 방문 처리 및 큐 삽입
    visited[start] = true;
    order[start] = ++cnt;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 2. 현재 노드와 연결된 인접 정점 확인
        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                order[next] = ++cnt; // 방문 순서 기록
                q.push(next);       // 큐에 넣기
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 3. 오름차순 방문을 위해 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}

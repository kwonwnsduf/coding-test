#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 사용을 위함

using namespace std;

vector<int> adj[1001];
bool visited[1001];

// 1. 깊이 우선 탐색 (DFS) - 재귀 사용
void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";

    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

// 2. 너비 우선 탐색 (BFS) - 큐 사용
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 양방향 연결
    }

    // 작은 번호부터 방문하기 위해 모든 인접 리스트 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS 실행
    dfs(V);
    cout << "\n";

    // 방문 배열 초기화 
    memset(visited, false, sizeof(visited));

    // BFS 실행
    bfs(V);
    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001]; // 인접 리스트
int order[100001];       // 각 정점의 방문 순서 저장
bool visited[100001];    // 방문 여부 확인
int cnt = 0;             // 순서 카운터

void dfs(int cur) {
    visited[cur] = true;
    order[cur] = ++cnt; // 방문할 때마다 순서 기록

    // 인접한 정점들을 순회
    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next);
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

    // 1. 오름차순 방문을 위해 각 정점의 인접 리스트 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 2. DFS 시작
    dfs(R);

    // 3. 결과 출력
    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}

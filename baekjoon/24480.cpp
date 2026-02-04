#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수로 선언하여 메모리 확보 및 DFS 접근 용이
vector<int> adj[100001];
int order[100001];
bool visited[100001];
int cnt = 0;

void dfs(int cur) {
    visited[cur] = true;
    order[cur] = ++cnt; // 방문 순서 저장

    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    // 입출력 가속
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

    //내림차순 정렬 
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}

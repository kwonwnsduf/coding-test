#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101]; // 컴퓨터 수는 100 이하
bool visited[101];
int infected_count = 0;

void dfs(int cur) {
    visited[cur] = true;

    for (int next : adj[cur]) {
        if (!visited[next]) {
            infected_count++; // 새로운 컴퓨터 감염!
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 양방향 연결
    }

    dfs(1); // 1번 컴퓨터부터 시작

    cout << infected_count << endl;

    return 0;
}

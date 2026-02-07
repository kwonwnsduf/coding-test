#include <iostream>
#include <vector>
#include <cstring> // memset 사용

using namespace std;

int M, N, K;
int map[51][51];
bool visited[51][51];
int dx[] = {0, 0, -1, 1}; // 상하좌우
int dy[] = {-1, 1, 0, 0};

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(ny, nx);
            }
        }
    }
}

void solve() {
    // 1. 초기화 및 입력
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1; // y가 행, x가 열
    }

    int worm_count = 0;

    // 2. 전체 지도 순회
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j); // 인접 배추들 싹 다 방문 처리
                worm_count++; // 지렁이 한 마리 추가
            }
        }
    }
    cout << worm_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

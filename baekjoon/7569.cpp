#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 3차원 좌표를 담기 위한 구조체
struct Pos {
    int z, y, x;
};

int M, N, H;
int box[101][101][101];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<Pos> q;

void bfs() {
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = cur.z + dz[i];
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            // 3차원 범위 체크
            if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = box[cur.z][cur.y][cur.x] + 1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    bool all_ripe = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push({i, j, k}); // 익은 토마토들 전부 큐에 삽입
                }
                if (box[i][j][k] == 0) all_ripe = false;
            }
        }
    }

    if (all_ripe) {
        cout << 0 << endl;
        return 0;
    }

    bfs();

    int max_days = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                max_days = max(max_days, box[i][j][k]);
            }
        }
    }

    cout << max_days - 1 << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
int box[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // 아직 익지 않은 토마토(0)를 발견하면
                if (box[nx][ny] == 0) {
                    // 이전 날짜 + 1 을 저장 (최초의 1일차 토마토가 1이므로 결과값에서 1 빼야함)
                    box[nx][ny] = box[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            // ★ 핵심: 익은 토마토를 발견하면 즉시 큐에 삽입 ★
            if (box[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    int max_days = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 하나라도 안 익은 게 있다면 실패
            if (box[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            max_days = max(max_days, box[i][j]);
        }
    }

    // 처음에 1일차부터 시작했으므로 1을 빼줌
    // (모두 익어있었다면 max_days가 1이므로 0이 출력됨)
    cout << max_days - 1 << endl;

    return 0;
}

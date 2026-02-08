#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
int dist[101][101]; // 방문 여부와 거리를 동시에 저장
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 1; // 시작 지점 거리 1

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나지 않고
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // 길이 있고(1), 아직 방문하지 않았다면(dist가 0)
                if (map[nx][ny] == 1 && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1; // 이전 칸 거리 + 1
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    bfs(0, 0);

    // 도착 지점의 최단 거리 출력
    cout << dist[N - 1][M - 1] << endl;

    return 0;
}

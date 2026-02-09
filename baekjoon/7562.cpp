#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int L; // 체스판의 한 변의 길이
int startX, startY, endX, endY;
int dist[301][301];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs() {
    // 만약 시작점과 도착점이 같다면 0보 반환
    if (startX == endX && startY == endY) return 0;

    memset(dist, -1, sizeof(dist)); // -1로 초기화 (방문 안 함)
    queue<pair<int, int>> q;

    q.push({startX, startY});
    dist[startX][startY] = 0; // 시작점 거리는 0

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 1. 체스판 범위 내에 있고
            if (nx >= 0 && nx < L && ny >= 0 && ny < L) {
                // 2. 아직 방문하지 않았다면
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    
                    // 목적지 도착 시 즉시 반환
                    if (nx == endX && ny == endY) return dist[nx][ny];
                    
                    q.push({nx, ny});
                }
            }
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> L;
        cin >> startX >> startY;
        cin >> endX >> endY;
        cout << bfs() << "\n";
    }
    return 0;
}

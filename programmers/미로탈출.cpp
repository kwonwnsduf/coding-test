#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상하좌우 이동을 위한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 특정 시작점(start_char)에서 목표점(target_char)까지의 최단 거리를 구하는 BFS 함수
int bfs(char start_char, char target_char, const vector<string>& board) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // 시작점 찾아서 큐에 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == start_char) {
                q.push({i, j});
                dist[i][j] = 0;
                break;
            }
        }
        if (!q.empty()) break;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 목표 지점에 도달했다면 거리 리턴
        if (board[x][y] == target_char) {
            return dist[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나지 않고, 벽('X')이 아니며, 아직 방문하지 않은 곳이라면
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (board[nx][ny] != 'X' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 큐가 빌 때까지 목표를 못 찾았으면 도달 불가 (-1 리턴)
    return -1;
}

int solution(vector<string> board) {
    // 1. 출발점(S) -> 레버(L) 최단 거리 구하기
    int time_to_lever = bfs('S', 'L', board);
    if (time_to_lever == -1) return -1; // 레버에 도달할 수 없으면 실패

    // 2. 레버(L) -> 출구(E) 최단 거리 구하기
    int time_to_exit = bfs('L', 'E', board);
    if (time_to_exit == -1) return -1; // 출구에 도달할 수 없으면 실패

    // 3. 두 거리의 합 리턴
    return time_to_lever + time_to_exit;
}

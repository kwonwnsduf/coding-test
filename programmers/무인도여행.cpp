#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상하좌우 이동을 위한 방향 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].size();
    
    // 방문 여부를 체크할 2차원 배열 (false로 초기화)
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 2차원 배열(지도) 전체 순회
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 바다가 아니면서('X'가 아님) 아직 방문하지 않은 땅(숫자)을 발견하면 탐색 시작
            if (maps[i][j] != 'X' && !visited[i][j]) {
                int sum = 0; // 이 섬에서 얻을 수 있는 총 식량
                queue<pair<int, int>> q;
                
                // 시작점 세팅
                q.push({i, j});
                visited[i][j] = true;
                
                // BFS(너비 우선 탐색) 시작
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    // 현재 위치의 식량을 더함 (char 형이므로 '0'을 빼서 정수로 변환)
                    sum += maps[x][y] - '0';
                    
                    // 상하좌우 4방향 탐색
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        // 지도를 벗어나지 않는지 확인
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            // 바다가 아니고 방문한 적이 없는 연결된 땅이라면
                            if (maps[nx][ny] != 'X' && !visited[nx][ny]) {
                                visited[nx][ny] = true; // 큐에 넣을 때 방문 처리
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                // 탐색이 끝난 섬의 총 식량을 정답 배열에 추가
                answer.push_back(sum);
            }
        }
    }

    // 발견된 섬이 하나도 없으면 -1 반환
    if (answer.empty()) {
        answer.push_back(-1);
    } else {
        // 식량을 오름차순으로 정렬
        sort(answer.begin(), answer.end());
    }

    return answer;
}

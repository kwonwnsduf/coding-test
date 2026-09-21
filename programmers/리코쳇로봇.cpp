#include <string>
#include <vector>
#include <queue>

using namespace std;

// 좌표와 이동 횟수를 담을 구조체
struct Node {
    int x, y, cnt;
};

// 상, 하, 좌, 우 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    
    int start_x = 0, start_y = 0;
    
    // 로봇의 시작 위치('R') 찾기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Node> q;
    
    q.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;
    
    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        
        // 목표 지점('G')에 도달한 경우
        if(board[curr.x][curr.y] == 'G') {
            return curr.cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = curr.x;
            int ny = curr.y;
            
            // 벽이나 장애물('D')을 만날 때까지 미끄러져 이동
            while(nx + dx[i] >= 0 && nx + dx[i] < n && 
                  ny + dy[i] >= 0 && ny + dy[i] < m && 
                  board[nx + dx[i]][ny + dy[i]] != 'D') {
                nx += dx[i];
                ny += dy[i];
            }
            
            // 멈춘 위치를 아직 방문하지 않았다면 큐에 추가
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.cnt + 1});
            }
        }
    }
    
    // 도달할 수 없는 경우
    return -1;
}

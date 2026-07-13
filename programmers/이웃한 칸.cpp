#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size(); // 격자의 크기
    
    // 상, 하, 좌, 우를 탐색하기 위한 방향 배열 (dh: 행 변화량, dw: 열 변화량)
    int dh[4] = {-1, 1, 0, 0};
    int dw[4] = {0, 0, -1, 1};
    
    // 현재 칸의 색상
    string target_color = board[h][w];
    
    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        // 격자 범위를 벗어나지 않는지 확인
        if (h_check >= 0 && h_check < n && w_check >= 0 && w_check < n) {
            // 이웃한 칸의 색상이 같은지 확인
            if (board[h_check][w_check] == target_color) {
                answer++;
            }
        }
    }
    
    return answer;
}

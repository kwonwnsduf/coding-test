#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();
    int W = park[0].size();
    
    // 1. 시작 위치(S) 찾기
    int cur_r = 0, cur_c = 0;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (park[r][c] == 'S') {
                cur_r = r;
                cur_c = c;
                break;
            }
        }
    }
    
    // 2. 명령 수행
    for (const string& route : routes) {
        char dir = route[0];
        int dist = route[2] - '0'; // "E 5" 형태이므로 인덱스 2가 거리입니다.
        
        int dr = 0, dc = 0;
        if (dir == 'N') dr = -1;
        else if (dir == 'S') dr = 1;
        else if (dir == 'W') dc = -1;
        else if (dir == 'E') dc = 1;
        
        int nr = cur_r;
        int nc = cur_c;
        bool valid = true;
        
        // 지정된 거리만큼 한 칸씩 이동 검사
        for (int i = 0; i < dist; ++i) {
            nr += dr;
            nc += dc;
            
            // 공원을 벗어나거나 장애물을 만난 경우
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || park[nr][nc] == 'X') {
                valid = false;
                break;
            }
        }
        
        // 이동 가능한 경우에만 좌표 업데이트
        if (valid) {
            cur_r = nr;
            cur_c = nc;
        }
    }
    
    return {cur_r, cur_c};
}

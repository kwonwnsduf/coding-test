#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int row = wallpaper.size();
    int col = wallpaper[0].size();
    
    // 시작점은 최댓값으로, 끝점은 최솟값으로 초기화
    int lux = row, luy = col;
    int rdx = 0, rdy = 0;
    
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            // 파일을 발견하면 위치 업데이트
            if (wallpaper[r][c] == '#') {
                lux = min(lux, r);
                luy = min(luy, c);
                rdx = max(rdx, r + 1);
                rdy = max(rdy, c + 1);
            }
        }
    }
    
    return {lux, luy, rdx, rdy};
}

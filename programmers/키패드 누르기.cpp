#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 키패드 번호별 (행, 열) 좌표 매핑
// index 0~9, *는 10, #는 11로 처리
pair<int, int> pos[12] = {
    {3, 1}, // 0
    {0, 0}, {0, 1}, {0, 2}, // 1, 2, 3
    {1, 0}, {1, 1}, {1, 2}, // 4, 5, 6
    {2, 0}, {2, 1}, {2, 2}, // 7, 8, 9
    {3, 0}, {3, 2}          // *(10), #(11)
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 처음 손가락 위치: 왼손 '*', 오른손 '#'
    int left_pos = 10;
    int right_pos = 11;

    for (int num : numbers) {
        // 1, 4, 7 -> 왼손
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left_pos = num;
        }
        // 3, 6, 9 -> 오른손
        else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right_pos = num;
        }
        // 2, 5, 8, 0 -> 거리 비교
        else {
            // 맨해튼 거리 계산 |x1 - x2| + |y1 - y2|
            int left_dist = abs(pos[left_pos].first - pos[num].first) + 
                            abs(pos[left_pos].second - pos[num].second);
            int right_dist = abs(pos[right_pos].first - pos[num].first) + 
                             abs(pos[right_pos].second - pos[num].second);

            if (left_dist < right_dist) {
                answer += 'L';
                left_pos = num;
            } else if (right_dist < left_dist) {
                answer += 'R';
                right_pos = num;
            } else { // 거리가 같을 때
                if (hand == "left") {
                    answer += 'L';
                    left_pos = num;
                } else {
                    answer += 'R';
                    right_pos = num;
                }
            }
        }
    }

    return answer;
}

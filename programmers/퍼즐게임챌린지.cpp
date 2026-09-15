#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 숙련도(level)로 제한 시간 내에 퍼즐을 모두 풀 수 있는지 확인하는 함수
bool canSolve(const vector<int>& diffs, const vector<int>& times, long long limit, int level) {
    long long total_time = 0;
    
    for (size_t i = 0; i < diffs.size(); ++i) {
        int diff = diffs[i];
        int time_cur = times[i];
        int time_prev = (i == 0) ? 0 : times[i - 1];
        
        if (diff <= level) {
            total_time += time_cur;
        } else {
            int fail_count = diff - level;
            // 틀린 횟수만큼 (현재 소요 시간 + 이전 소요 시간)을 더하고, 마지막에 현재 퍼즐을 깨는 시간 추가
            total_time += (long long)fail_count * (time_cur + time_prev) + time_cur;
        }
        
        // 중간에 이미 제한 시간을 초과하면 더 볼 필요 없음
        if (total_time > limit) {
            return false;
        }
    }
    
    return total_time <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = 0;
    
    // 숙련도의 최댓값은 diffs 중 가장 큰 값으로 설정
    for (int d : diffs) {
        right = max(right, d);
    }
    
    int answer = right;
    
    // 이분 탐색 수행
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canSolve(diffs, times, limit, mid)) {
            answer = mid;       // 가능다면 기록해두고 더 작은 숙련도가 가능한지 탐색
            right = mid - 1;
        } else {
            left = mid + 1;     // 불가능하다면 숙련도를 높여야 함
        }
    }
    
    return answer;
}

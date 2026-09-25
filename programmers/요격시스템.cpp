#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 끝점 기준 오름차순 정렬 함수
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    // 1. 끝점(end)을 기준으로 오름차순 정렬
    sort(targets.begin(), targets.end(), cmp);

    int last_end = 0; // 직전 미사일의 요격 끝점 (또는 직전 요격 위치)

    for (int i = 0; i < targets.size(); i++) {
        int start = targets[i][0];
        int end = targets[i][1];

        // 2. 현재 미사일의 시작점이 직전 요격 끝점 이상이면 새로운 요격 필요
        if (start >= last_end) {
            answer++;
            last_end = end; // 새로운 요격 위치를 현재 미사일의 끝점으로 설정
        }
    }

    return answer;
}

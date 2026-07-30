#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int max_painted = 0; // 지금까지 페인트칠로 커버된 마지막 구역 번호

    for (int s : section) {
        // 현재 칠해야 할 구역이 기존 칠한 범위를 벗어난 경우
        if (s > max_painted) {
            answer++;                  // 칠하는 횟수 증가
            max_painted = s + m - 1;   // 현재 구역부터 m만큼 칠함
        }
    }

    return answer;
}

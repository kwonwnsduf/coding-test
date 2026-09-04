#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero_count = 0;

    // 1. 0의 개수 카운트
    for (int num : lottos) {
        if (num == 0) zero_count++;
    }

    // 2. 두 배열 오름차순 정렬
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int match_count = 0;
    int i = 0; // lottos 포인터
    int j = 0; // win_nums 포인터

    // 3. 투 포인터 탐색
    while (i < lottos.size() && j < win_nums.size()) {
        // 0은 번호 비교 대상이 아니므로 패스
        if (lottos[i] == 0) {
            i++;
            continue;
        }

        if (lottos[i] == win_nums[j]) {      // 같은 번호를 찾음!
            match_count++;
            i++;
            j++;
        } 
        else if (lottos[i] < win_nums[j]) { // 내 번호가 더 작으면 다음 내 번호 확인
            i++;
        } 
        else {                              // 당첨 번호가 더 작으면 다음 당첨 번호 확인
            j++;
        }
    }

    // 4. 최고/최저 맞춤 개수를 순위로 변환 (배열 매핑 활용)
    // index : 맞춘 개수 [0개, 1개, 2개, 3개, 4개, 5개, 6개]
    int rank[] = {6, 6, 5, 4, 3, 2, 1};

    int max_match = match_count + zero_count;
    int min_match = match_count;

    return {rank[max_match], rank[min_match]};
}

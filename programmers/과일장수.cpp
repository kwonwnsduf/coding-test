#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 1. 내림차순 정렬
    sort(score.begin(), score.end(), greater<int>());
    
    int count = 0;
    int min_score = k; // 최소값 추적용 변수
    
    // 2. 1씩 늘려가면서 탐색
    for (int i = 0; i < score.size(); i++) {
        count++;
        min_score = min(min_score, score[i]); // 현재 사과의 점수와 비교해 최솟값 갱신
        
        // 3. 카운트가 m이 되면 계산
        if (count == m) {
            answer += min_score * m;
            
            // 4. 카운트와 최솟값 초기화
            count = 0;
            min_score = k;
        }
    }
    
    return answer;
}

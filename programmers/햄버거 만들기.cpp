#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> s; // 스택 역할을 할 벡터
    
    for (int i : ingredient) {
        s.push_back(i);
        
        // 스택에 재료가 4개 이상 모였을 때 확인
        if (s.size() >= 4) {
            int n = s.size();
            // 맨 뒤에서부터 4개 재료가 1, 2, 3, 1 인지 검사
            if (s[n - 4] == 1 && s[n - 3] == 2 && s[n - 2] == 3 && s[n - 1] == 1) {
                answer++;
                // 햄버거에 사용된 재료 4개 제거
                for (int j = 0; j < 4; j++) {
                    s.pop_back();
                }
            }
        }
    }
    
    return answer;
}

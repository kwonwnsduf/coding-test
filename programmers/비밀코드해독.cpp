#include <string>
#include <vector>

using namespace std;

int answer_count = 0;

// 주어진 후보 조합이 모든 시도 조건을 만족하는지 검사하는 함수
bool isValid(const vector<int>& candidate, const vector<vector<int>>& q, const vector<int>& ans) {
    for (size_t i = 0; i < q.size(); ++i) {
        int match = 0;
        for (int c : candidate) {
            for (int x : q[i]) {
                if (c == x) {
                    match++;
                    break;
                }
            }
        }
        // 시도 결과와 일치하지 않는다면 유효하지 않은 비밀 코드
        if (match != ans[i]) {
            return false;
        }
    }
    return true;
}

// 백트래킹을 이용해 1부터 n까지의 수 중 5개를 고르는 조합 생성
void dfs(int start, int depth, vector<int>& current, int n, const vector<vector<int>>& q, const vector<int>& ans) {
    if (depth == 5) {
        if (isValid(current, q, ans)) {
            answer_count++;
        }
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        dfs(i + 1, depth + 1, current, n, q, ans);
        current.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    answer_count = 0;
    vector<int> current;
    
    // 1부터 n까지의 수 중 5개를 뽑는 조합 탐색 시작
    dfs(1, 0, current, n, q, ans);
    
    return answer_count;
}

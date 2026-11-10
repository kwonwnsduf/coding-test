#include <string>
#include <vector>

using namespace std;

// DFS를 위한 재귀 함수
void dfs(int depth, vector<int>& rates, const vector<vector<int>>& users, const vector<int>& emoticons, int& max_plus, int& max_revenue) {
    // 모든 이모티콘의 할인율이 정해진 경우 (종료 조건)
    if (depth == emoticons.size()) {
        int plus_count = 0;  // 현재 할인율 조합에서의 플러스 가입자 수
        int revenue = 0;     // 현재 할인율 조합에서의 판매액
        
        for (const auto& user : users) {
            int threshold = user[0]; // 사용자가 구매를 결정하는 최소 할인율
            int budget = user[1];    // 사용자의 예산(플러스 가입 기준)
            int sum = 0;             // 이 사용자의 총 구매 비용
            
            // 각 이모티콘을 순회하며 구매 비용 계산
            for (int i = 0; i < emoticons.size(); i++) {
                // 사용자가 원하는 할인율 이상일 때만 구매
                if (rates[i] >= threshold) {
                    sum += emoticons[i] * (100 - rates[i]) / 100;
                }
            }
            
            // 예산을 초과하면 플러스 가입, 아니면 단품 구매
            if (sum >= budget) {
                plus_count++;
            } else {
                revenue += sum;
            }
        }
        
        // 1순위 목표: 플러스 가입자 수 늘리기
        if (plus_count > max_plus) {
            max_plus = plus_count;
            max_revenue = revenue;
        } 
        // 2순위 목표: 가입자 수가 같다면 판매액 늘리기
        else if (plus_count == max_plus && revenue > max_revenue) {
            max_revenue = revenue;
        }
        
        return;
    }
    
    // 할인율 4가지 경우의 수를 백트래킹으로 모두 탐색
    int discounts[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        rates.push_back(discounts[i]); // 할인율 적용
        dfs(depth + 1, rates, users, emoticons, max_plus, max_revenue); // 다음 이모티콘으로
        rates.pop_back(); // 상태 복구 (백트래킹)
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int max_plus = 0;
    int max_revenue = 0;
    vector<int> rates; // 이모티콘별 적용된 할인율을 담을 배열
    
    // 깊이 0(첫 번째 이모티콘)부터 탐색 시작
    dfs(0, rates, users, emoticons, max_plus, max_revenue);
    
    return {max_plus, max_revenue};
}

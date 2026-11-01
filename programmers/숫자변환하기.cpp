#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 도달 불가능을 나타내는 매우 큰 값 (1,000,000 연산을 넘지 않으므로 적당히 큰 수 지정)
const int INF = 1e9; 

int solution(int x, int y, int n) {
    // 이미 x와 y가 같다면 연산이 필요 없음
    if (x == y) return 0;
    
    // dp[i] : x를 i로 만드는데 필요한 최소 연산 횟수
    vector<int> dp(y + 1, INF);
    
    // 시작점 초기화
    dp[x] = 0;
    
    // x부터 y까지 순차적으로 탐색
    for (int i = x; i <= y; i++) {
        // 도달할 수 없는 숫자면 패스
        if (dp[i] == INF) continue;
        
        // 1. i + n
        if (i + n <= y) {
            dp[i + n] = min(dp[i + n], dp[i] + 1);
        }
        
        // 2. i * 2
        if (i * 2 <= y) {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        
        // 3. i * 3
        if (i * 3 <= y) {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
    }
    
    // 목표값 y에 도달할 수 없다면 -1, 도달했다면 최소 횟수 반환
    return dp[y] == INF ? -1 : dp[y];
}

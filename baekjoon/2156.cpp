#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wine(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    // 초기값 설정
    dp[1] = wine[1];
    if (n >= 2) dp[2] = wine[1] + wine[2];
    
    // 3번째 잔부터 점화식 적용
    for (int i = 3; i <= n; i++) {
        // 상황 1: i번째를 안 마심 (dp[i-1])
        // 상황 2: i번째를 마심(i-1은 안 마심) (dp[i-2] + wine[i])
        // 상황 3: i번째를 마심(i-1도 마심) (dp[i-3] + wine[i-1] + wine[i])
        dp[i] = max({dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]});
    }

    cout << dp[n] << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stair(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }

    // 초기값 설정 (계단 개수에 따라 예외 처리 필요)
    dp[1] = stair[1];
    if (n >= 2) dp[2] = stair[1] + stair[2];
    if (n >= 3) dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    // 점화식 적용
    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 3] + stair[i - 1], dp[i - 2]) + stair[i];
    }

    cout << dp[n] << endl;

    return 0;
}

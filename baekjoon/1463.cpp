#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // dp[i]는 숫자 i를 1로 만드는 최소 연산 횟수
    vector<int> dp(n + 1);

    dp[1] = 0; // 1은 이미 1이므로 연산 0번

    for (int i = 2; i <= n; i++) {
        // 1. 먼저 1을 빼는 경우를 기본값으로 설정
        dp[i] = dp[i - 1] + 1;

        // 2. 2로 나누어 떨어지면, 2로 나눴을 때의 횟수와 비교
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // 3. 3으로 나누어 떨어지면, 3으로 나눴을 때의 횟수와 비교
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}

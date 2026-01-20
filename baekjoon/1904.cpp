#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // N이 1일 때 dp[2]를 참조하면 에러가 날 수 있으므로 넉넉하게 할당
    vector<int> dp(N + 1);

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        // 점화식 적용 및 나머지 연산
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[N] << endl;

    return 0;
}

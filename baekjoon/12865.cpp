#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1);
    vector<int> V(N + 1);
    // dp[물건번호][무게]
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j) {
                // 현재 물건을 넣을 수 있는 경우
                // (안 넣었을 때의 최적값) vs (현재 물건 무게를 뺀 상태의 최적값 + 현재 가치)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            } else {
                // 현재 물건을 넣을 수 없는 경우
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    // 2차원 DP 테이블 (인덱스 에러 방지를 위해 크기를 +1)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // 문자가 같으면 대각선 왼쪽 위 값 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 문자가 다르면 위쪽과 왼쪽 중 큰 값
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

long long dp[101][10];
const int MOD = 1000000000;

int main() {
    int N;
    cin >> N;

    // 길이가 1인 계단 수 초기화 (0으로 시작하는 수는 없음)
    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }

    // 길이가 2부터 N까지 DP 테이블 채우기
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % MOD;
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    // 결과 합산
    long long result = 0;
    for (int j = 0; j <= 9; j++) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N, 1); // 모든 길이를 1로 초기화

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // 내(A[i]) 앞에 나보다 작은 놈(A[j])이 있다면?
            if (A[j] < A[i]) {
                // 그 놈 뒤에 붙는 게 현재 나보다 길다면 갱신!
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]); // 전체 중 가장 긴 놈 찾기
    }

    cout << ans << endl;
    return 0;
}

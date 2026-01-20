#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 초기값: 첫 번째 원소는 그 자체로 최대합
    dp[0] = arr[0];
    int max_result = dp[0];

    for (int i = 1; i < n; i++) {
        // 이전까지의 합에 나를 더한 것 vs 그냥 나부터 새로 시작하는 것
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        
        // 전체 결과값 갱신
        if (dp[i] > max_result) {
            max_result = dp[i];
        }
    }

    cout << max_result << endl;

    return 0;
}

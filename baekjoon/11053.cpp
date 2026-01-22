#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n, 1); // 모든 위치의 최소 길이는 1

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_len = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // 앞에 있는 숫자(j)가 현재 숫자(i)보다 작다면
            if (arr[j] < arr[i]) {
                // j번째에서 끝나는 수열 뒤에 i를 붙이는 것이 더 긴지 확인
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 전체 수열 중 가장 큰 값을 계속 갱신
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << endl;

    return 0;
}

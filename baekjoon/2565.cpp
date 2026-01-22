#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> line(N);
    for (int i = 0; i < N; i++) cin >> line[i].first >> line[i].second;

    // 1. 왼쪽 번호 기준으로 정렬
    sort(line.begin(), line.end());

    // 2. 오른쪽 번호들로 LIS 구하기
    vector<int> dp(N, 1);
    int max_lis = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (line[j].second < line[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_lis = max(max_lis, dp[i]);
    }

    // 3. 최소 제거 개수 = 전체 - LIS 길이
    cout << N - max_lis << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temp(N + 1);
    vector<int> S(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> temp[i];
        // 누적 합 계산
        S[i] = S[i - 1] + temp[i];
    }

    // 최댓값을 저장할 변수 (최소치로 초기화)
    // 온도가 음수일 수 있으므로 매우 작은 값으로 시작해야 함
    int max_sum = -1e9; 

    // 길이가 K인 모든 구간을 검사 (i는 구간의 끝 지점)
    for (int i = K; i <= N; i++) {
        int current_sum = S[i] - S[i - K];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;

    return 0;
}

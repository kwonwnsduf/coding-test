#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    long long low = 1, high = K; // K번째 수는 K보다 클 수 없음
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;

        // mid보다 작거나 같은 숫자가 행렬에 총 몇 개 있는지 계산
        for (int i = 1; i <= N; i++) {
            count += min(mid / i, N);
        }

        if (count >= K) {
            // 개수가 K보다 많거나 같다면, mid는 정답 후보!
            // 더 작은 숫자 중에도 정답이 있는지 확인
            ans = mid;
            high = mid - 1;
        } else {
            // 개수가 부족하면 mid를 더 키워야 함
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<long long> lines(K);
    long long max_len = 0;

    for (int i = 0; i < K; i++) {
        cin >> lines[i];
        if (lines[i] > max_len) max_len = lines[i];
    }

    // 이분 탐색 범위 설정
    long long low = 1;
    long long high = max_len;
    long long result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2; // 자를 랜선의 길이 후보
        long long count = 0;

        // 1. mid 길이로 잘랐을 때 몇 개가 나오는지 계산
        for (int i = 0; i < K; i++) {
            count += (lines[i] / mid);
        }

        // 2. 조건 판단
        if (count >= N) {
            // N개보다 많이 혹은 딱 맞게 만들 수 있다면? 
            // 더 길게 잘라볼 가능성이 있으므로 오른쪽 탐색
            result = mid; 
            low = mid + 1;
        } else {
            // N개를 못 만든다면? 너무 길게 잡은 것이므로 왼쪽 탐색
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}

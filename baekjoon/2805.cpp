#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M; // 필요한 나무 길이 (범위가 큼)
    cin >> N >> M;

    vector<long long> trees(N);
    long long max_tree = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_tree) max_tree = trees[i];
    }

    // 이분 탐색 범위 설정 (0부터 가장 높은 나무 높이까지)
    long long low = 0;
    long long high = max_tree;
    long long result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2; // 절단기의 높이 후보
        long long total = 0; // 잘린 나무들의 합

        // 현재 높이(mid)로 잘랐을 때 얻을 수 있는 나무 양 계산
        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                total += (trees[i] - mid);
            }
        }

        // 조건 판단 (파라메트릭 서치)
        if (total >= M) {
            // 나무가 충분하거나 남음 -> 절단기 높이를 더 높여보자
            result = mid; 
            low = mid + 1;
        } else {
            // 나무가 부족함 -> 절단기 높이를 낮춰야 함
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}

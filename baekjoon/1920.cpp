#include <iostream>
#include <vector>
#include <algorithm> // sort, binary_search 사용

using namespace std;

int main() {
    // 1. 입출력 속도 향상 (안 하면 시간 초과 날 수 있음)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    // 2. 기준이 되는 숫자들 입력 받기
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 3. ★중요★ 이분 탐색을 하려면 반드시 먼저 정렬되어 있어야 함!
    sort(A.begin(), A.end());

    // 4. 찾을 숫자들 입력 받으며 즉시 탐색
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;

        // binary_search(시작, 끝, 찾을값) -> 있으면 true, 없으면 false 반환
        if (binary_search(A.begin(), A.end(), target)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}

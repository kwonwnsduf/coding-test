#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도를 높이기 위한 필수 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> S(N + 1, 0); // 누적 합 배열

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        // S[i] = (1~i-1까지의 합) + 현재 숫자
        S[i] = S[i - 1] + temp;
    }

    for (int k = 0; k < M; k++) {
        int i, j;
        cin >> i >> j;
        // 구간 합 공식 적용
        cout << S[j] - S[i - 1] << "\n";
    }

    return 0;
}

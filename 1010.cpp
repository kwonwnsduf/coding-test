#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        // mCn 계산
        // nCr = n! / (r! * (n-r)!)
        // 결과값이 커질 수 있으므로 long long 권장
        long long result = 1;

        // nCr에서 r이 n/2보다 크면 nC(n-r)로 계산하는 것이 효율적
        if (N > M / 2) N = M - N;

        for (int i = 1; i <= N; i++) {
            result *= M--;
            result /= i;
        }

        cout << result << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), up(N, 1), down(N, 1);
    for (int i = 0; i < N; i++) cin >> A[i];

    // LIS 계산 (앞에서부터)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            if (A[j] < A[i]) up[i] = max(up[i], up[j] + 1);

    // LDS 계산 (뒤에서부터)
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j > i; j--)
            if (A[j] < A[i]) down[i] = max(down[i], down[j] + 1);

    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, up[i] + down[i] - 1);
    cout << ans << endl;
    return 0;
}

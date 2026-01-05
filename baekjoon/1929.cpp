#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. 빠른 입출력 (백만 개의 데이터를 처리할 때 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    // 2. 에라토스테네스의 체 초기화
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            // i의 배수들을 false로 바꿈
            // i*i 이전의 배수들은 이미 이전 단계에서 처리됨
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 3. M이상 N이하의 소수 출력
    for (int i = M; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}

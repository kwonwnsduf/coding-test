#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
bool is_prime[MAX + 1];

// 1. 에라토스테네스의 체로 소수 미리 판별
void sieve() {
    for (int i = 2; i <= MAX; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    // 빠른 입출력 필수
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count = 0;
        // 2. n = a + b 에서 a가 소수이면 b(n-a)가 소수인지 확인
        // 중복을 피하기 위해 i는 N/2까지만 루프를 돕니다.
        for (int i = 2; i <= N / 2; i++) {
            if (is_prime[i] && is_prime[N - i]) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}

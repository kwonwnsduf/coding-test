#include <iostream>

using namespace std;

// 소수 판별 함수 (long long 사용 필수)
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 2부터 루트 n까지 나누어 떨어지는지 확인
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        // n부터 시작해서 소수를 찾을 때까지 1씩 증가
        while (!isPrime(n)) {
            n++;
        }
        cout << n << "\n";
    }

    return 0;
}

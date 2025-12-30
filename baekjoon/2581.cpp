#include <iostream>
#include <vector>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2) return false; // 1은 소수가 아님
    for (int i = 2; i * i <= n; i++) { // 제곱근까지만 확인
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;

    int sum = 0;
    int minPrime = -1;

    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            if (minPrime == -1) {
                minPrime = i; // 첫 번째로 발견된 소수가 최솟값
            }
            sum += i;
        }
    }

    if (minPrime == -1) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << minPrime << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// 문제에서 주어진 n의 최대치 123,456의 2배
const int MAX = 123456 * 2;
bool is_prime[MAX + 1];

void sieve() {
    // 배열 초기화 (처음엔 모두 소수라고 가정)
    for (int i = 2; i <= MAX; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false; // i의 배수들을 제거
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(); // 프로그램 시작 시 한 번만 소수 체를 만들어둠

    int n;
    while (cin >> n && n != 0) {
        int count = 0;
        // n 초과 2n 이하의 소수 개수 세기
        for (int i = n + 1; i <= 2 * n; i++) {
            if (is_prime[i]) count++;
        }
        cout << count << "\n";
    }

    return 0;
}

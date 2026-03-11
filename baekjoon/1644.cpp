#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n == 1) { // 1은 소수가 아니므로 바로 0 출력
        cout << 0 << "\n";
        return 0;
    }

    // 1. 에라토스테네스의 체로 소수 구하기
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    // 2. 투 포인터로 연속합 찾기
    int start = 0, end = 0, sum = 0, count = 0;
    int m = primes.size();

    while (true) {
        if (sum >= n) {
            if (sum == n) count++;
            sum -= primes[start++];
        } 
        else if (end == m) {
            break;
        } 
        else {
            sum += primes[end++];
        }
    }

    cout << count << "\n";

    return 0;
}

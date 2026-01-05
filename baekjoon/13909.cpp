#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;

    int count = 0;
    // 1부터 시작해서 제곱이 N보다 작거나 같을 때까지 반복
    for (long long i = 1; i * i <= N; i++) {
        count++;
    }

    cout << count << endl;

    return 0;
}

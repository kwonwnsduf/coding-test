#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else
		return gcd(b, a % b);
}
int main() {
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    // 1. 통분하여 합산된 분자와 분모 구하기
    // 분모: b1 * b2
    // 분자: a1 * b2 + a2 * b1
    long long child = a1 * b2 + a2 * b1;
    long long parent = b1 * b2;

    // 2. 분자와 분모의 최대공약수 구하기
    long long common = gcd(child, parent);

    // 3. 최대공약수로 약분하여 출력
    cout << child / common << " " << parent / common << endl;

    return 0;

}

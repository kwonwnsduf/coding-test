#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else
		return gcd(b, a % b);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		int g=gcd(A, B);
		int result = A * B / g;
		cout << result << endl;
	}


}

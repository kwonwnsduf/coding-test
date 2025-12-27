#include<iostream>
using namespace std;
int main()
{
	int H, M;
	cin >> H >> M;
	int a = M - 45;
	if (a < 0) {
		H = H - 1;
		M = a + 60;
		if (H < 0) {
			H = 23;
	}
		}
	else {
		M = a;
	}
	cout << H << " " << M << "\n";
}

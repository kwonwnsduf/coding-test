#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int bags = 0;

    while (N >= 0) {
        // N이 5로 딱 나누어떨어지면, 그게 최선입니다.
        if (N % 5 == 0) {
            bags += (N / 5);
            cout << bags << endl;
            return 0;
        }
        
        // 5로 안 나누어지면 3kg 봉지를 하나 쓰고 다시 검사합니다.
        N -= 3;
        bags++;
    }

    // N이 0보다 작아질 때까지 못 찾으면 정확하게 만들 수 없는 무게입니다.
    cout << -1 << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // 1. max를 -1로 초기화하여 0이 입력되어도 조건문이 실행되게 함
    int maxValue = -1;
    int a = 1, b = 1;
    int input;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> input;

            // 2. 입력값이 현재 maxValue보다 크면 값과 위치 저장
            if (input > maxValue) {
                maxValue = input;
                a = i;
                b = j;
            }
        }
    }

    // 3. 출력 시 공백과 개행 처리
    cout << maxValue << "\n";
    cout << a << " " << b << endl;

    return 0;
}

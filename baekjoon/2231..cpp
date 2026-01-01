#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int sum = i;      // 자기 자신으로 시작
        int temp = i;     // 자릿수를 계산할 임시 변수

        // 각 자릿수를 더해주는 while문
        while (temp > 0) {
            sum += temp % 10; // 1의 자릿수 더하기
            temp /= 10;       // 1의 자릿수 버리기
        }

        if (sum == N) {
            cout << i << endl; // 가장 작은 생성자 발견 시 출력
            return 0;          // 프로그램 종료
        }
    }

    // for문이 다 돌 때까지 return 되지 않았다면 생성자가 없는 것임
    cout << 0 << endl;
    return 0;
}

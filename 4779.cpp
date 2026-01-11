#include <iostream>
#include <cmath>

using namespace std;

// 재귀적으로 칸토어 집합을 출력하는 함수
void cantor(int n) {
    // 기본 단계: n이 0이면 길이가 1이므로 '-' 출력
    if (n == 0) {
        cout << "-";
        return;
    }

    // 1. 왼쪽 3분의 1 구간 재귀 호출
    cantor(n - 1);

    // 2. 가운데 3분의 1 구간 공백 출력
    // 공백의 개수는 3^(n-1)개
    int space_count = pow(3, n - 1);
    for (int i = 0; i < space_count; i++) {
        cout << " ";
    }

    // 3. 오른쪽 3분의 1 구간 재귀 호출
    cantor(n - 1);
}

int main() {
    int N;
    // 파일의 끝(EOF)까지 입력을 받는 방식
    while (cin >> N) {
        cantor(N);
        cout << "\n";
    }

    return 0;
}

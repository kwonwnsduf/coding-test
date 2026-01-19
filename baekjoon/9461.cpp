#include <iostream>
using namespace std;

int main() {
    // 입출력 속도 향상 (선택사항이지만 권장)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // 1. long long 타입을 사용하여 오버플로우 방지
    // 2. N=100까지 담기 위해 크기를 101로 설정
    long long p[101];

    // 3. 문제에 주어진 초기값 정확히 설정 (1번째부터 사용)
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;

    // 4. 점화식을 6번째 항부터 적용
    for(int i = 6; i <= 100; i++) {
        p[i] = p[i-2] + p[i-3];
    }

    while(T--) {
        int n;
        cin >> n;
        // 배열 인덱스 주의 (1부터 시작하도록 설정했으므로 p[n])
        cout << p[n] << "\n";
    }

    return 0;
}

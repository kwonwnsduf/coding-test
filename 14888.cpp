#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int numbers[12];
int operators[4]; // +, -, *, / 순서
int max_val = -1e9; // 최댓값 초기화 (최소 가능한 값보다 작게)
int min_val = 1e9;  // 최솟값 초기화 (최대 가능한 값보다 크게)

void solve(int current_result, int idx) {
    // 모든 숫자를 다 계산했다면 결과 기록
    if (idx == N) {
        max_val = max(max_val, current_result);
        min_val = min(min_val, current_result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) { // 해당 연산자가 남아있다면
            operators[i]--; // 연산자 사용

            if (i == 0) solve(current_result + numbers[idx], idx + 1);
            else if (i == 1) solve(current_result - numbers[idx], idx + 1);
            else if (i == 2) solve(current_result * numbers[idx], idx + 1);
            else if (i == 3) solve(current_result / numbers[idx], idx + 1);

            operators[i]++; // 백트래킹: 연산자 개수 복구
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    // 첫 번째 숫자를 시작 결과값으로 넘겨줌
    solve(numbers[0], 1);

    cout << max_val << "\n" << min_val << endl;

    return 0;
}

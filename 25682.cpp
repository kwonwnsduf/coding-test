#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
char board[2001][2001];

// 패턴과 비교하여 틀린 개수를 누적 합으로 반환하는 함수
int solve(char color) {
    vector<vector<int>> p_sum(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int value = 0;
            // 체스판의 규칙: (행+열)이 짝수면 시작색과 같아야 하고, 홀수면 달라야 함
            if ((i + j) % 2 == 0) {
                if (board[i][j] != color) value = 1;
            } else {
                if (board[i][j] == color) value = 1;
            }
            // 2차원 누적 합 공식
            p_sum[i][j] = p_sum[i - 1][j] + p_sum[i][j - 1] - p_sum[i - 1][j - 1] + value;
        }
    }

    int min_paint = K * K;
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            // 2차원 구간 합 공식으로 KxK 영역의 틀린 개수 계산
            int current_paint = p_sum[i][j] - p_sum[i - K][j] - p_sum[i][j - K] + p_sum[i - K][j - K];
            
            // B 시작 패턴에서의 개수(current_paint)와 
            // W 시작 패턴에서의 개수(K*K - current_paint) 중 최솟값 선택
            min_paint = min({min_paint, current_paint, K * K - current_paint});
        }
    }
    return min_paint;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    // 어느 색으로 시작하든 상관없음 (함수 내부에서 K*K - count로 둘 다 체크하기 때문)
    cout << solve('B') << endl;

    return 0;
}

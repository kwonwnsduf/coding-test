#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int S[21][21];
bool is_start_team[21];
int min_diff = 1e9;

void calculate_diff() {
    int start_score = 0;
    int link_score = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_start_team[i] && is_start_team[j]) {
                start_score += S[i][j];
            }
            else if (!is_start_team[i] && !is_start_team[j]) {
                link_score += S[i][j];
            }
        }
    }

    int diff = abs(start_score - link_score);
    if (diff < min_diff) min_diff = diff;
}

void solve(int idx, int count) {
    // N/2명을 다 뽑았다면 점수 계산
    if (count == N / 2) {
        calculate_diff();
        return;
    }

    // idx부터 N까지 탐색하며 조합 생성
    for (int i = idx; i < N; i++) {
        if (!is_start_team[i]) {
            is_start_team[i] = true;
            solve(i + 1, count + 1); // i+1을 넘겨주어 중복 조합 방지
            is_start_team[i] = false; // 백트래킹: 상태 복구
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    solve(0, 0);

    cout << min_diff << endl;

    return 0;
}

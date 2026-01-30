#include <iostream>
#include <vector>

using namespace std;

int paper[129][129];
int white = 0;
int blue = 0;

// (r, c)에서 시작하는 N x N 크기의 종이가 모두 같은 색인지 확인
void solve(int r, int c, int N) {
    int color = paper[r][c]; // 첫 번째 칸의 색을 기준으로 잡음
    bool same = true;

    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++) {
            if (paper[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        // 모두 같은 색이면 해당 색 카운트 증가
        if (color == 0) white++;
        else blue++;
    } else {
        // 색이 섞여 있으면 4등분하여 재귀 호출
        int nextN = N / 2;
        solve(r, c, nextN);               // 왼쪽 위
        solve(r, c + nextN, nextN);       // 오른쪽 위
        solve(r + nextN, c, nextN);       // 왼쪽 아래
        solve(r + nextN, c + nextN, nextN); // 오른쪽 아래
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << "\n" << blue << "\n";

    return 0;
}

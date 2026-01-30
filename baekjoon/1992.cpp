#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int board[64][64];

void solve(int r, int c, int size) {
    int current = board[r][c];
    bool isSame = true;

    // 현재 영역이 모두 같은지 체크
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (board[i][j] != current) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        // 모두 같으면 숫자 출력
        cout << current;
    } else {
        // 섞여 있으면 괄호를 열고 4등분
        cout << "(";
        int nextSize = size / 2;
        solve(r, c, nextSize);                   // 1. 왼쪽 위
        solve(r, c + nextSize, nextSize);         // 2. 오른쪽 위
        solve(r + nextSize, c, nextSize);         // 3. 왼쪽 아래
        solve(r + nextSize, c + nextSize, nextSize); // 4. 오른쪽 아래
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j] - '0'; // 문자를 숫자로 변환
        }
    }

    solve(0, 0, N);
    cout << endl;

    return 0;
}

#include <string>
#include <vector>

using namespace std;

// 특정 플레이어(c)가 이겼는지 확인하는 함수
bool checkWin(const vector<string>& board, char c) {
    // 가로 줄 검사
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
    }
    // 세로 줄 검사
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
    }
    // 대각선 검사
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

    return false;
}

int solution(vector<string> board) {
    int countO = 0, countX = 0;

    // 1. O와 X의 개수 세기
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') countO++;
            else if (board[i][j] == 'X') countX++;
        }
    }

    // 2. 개수 규칙 위반 검사 (O는 X와 같거나 1개만 더 많아야 함)
    if (countO < countX || countO > countX + 1) return 0;

    bool winO = checkWin(board, 'O');
    bool winX = checkWin(board, 'X');

    // 3. 둘 다 동시에 이길 수는 없음
    if (winO && winX) return 0;

    // 4. O가 이겼다면, 반드시 O가 마지막 수(countO == countX + 1)를 두었어야 함
    if (winO && countO != countX + 1) return 0;

    // 5. X가 이겼다면, 반드시 X가 마지막 수(countO == countX)를 두었어야 함
    if (winX && countO != countX) return 0;

    return 1;
}

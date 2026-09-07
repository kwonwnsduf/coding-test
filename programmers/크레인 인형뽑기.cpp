#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; // 터진 인형의 개수
    stack<int> basket; // 인형을 담을 바구니

    int N = board.size(); // 격자판의 크기 (N x N)

    for (int col : moves) {
        int c = col - 1; // 1-based 인덱스를 0-based 인덱스로 변환

        // 해당 열에서 가장 위에 있는 인형 찾기
        for (int r = 0; r < N; r++) {
            if (board[r][c] != 0) { // 인형을 발견한 경우
                int doll = board[r][c];
                board[r][c] = 0; // 인형을 꺼냈으므로 빈 공간(0)으로 변경

                // 바구니에 인형이 있고, 맨 위 인형과 같은 종류라면 터뜨림
                if (!basket.empty() && basket.top() == doll) {
                    basket.pop();
                    answer += 2; // 인형 2개가 사라짐
                } 
                // 그렇지 않다면 바구니에 담음
                else {
                    basket.push(doll);
                }

                break; // 인형을 1개 뽑았으므로 다음 moves로 이동
            }
        }
    }

    return answer;
}

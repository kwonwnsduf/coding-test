#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char x = ' ';
    int same = 0;
    int diff = 0;

    for (char c : s) {
        // 분리 후 새로운 덩어리를 시작하는 시점
        if (same == 0) {
            x = c;
            same = 1;
            continue;
        }

        // 문자에 따라 카운트 증가
        if (c == x) {
            same++;
        } else {
            diff++;
        }

        // x의 횟수와 x가 아닌 글자의 횟수가 같아지면 분리
        if (same == diff) {
            answer++;
            same = 0;
            diff = 0;
        }
    }

    // 반복문이 끝났는데 아직 분리되지 않고 남아있는 문자열이 있다면 처리
    if (same > 0) {
        answer++;
    }

    return answer;
}

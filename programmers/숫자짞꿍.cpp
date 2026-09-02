#include <string>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    // 1. 두 문자열을 모두 내림차순 정렬 ('9' -> '0')
    sort(X.begin(), X.end(), greater<char>());
    sort(Y.begin(), Y.end(), greater<char>());

    string answer = "";
    int i = 0, j = 0;

    // 2. 투 포인터로 공통 숫자 찾기
    while (i < X.length() && j < Y.length()) {
        if (X[i] == Y[j]) {      // 숫자가 같으면 짝꿍!
            answer += X[i];
            i++;
            j++;
        } 
        else if (X[i] > Y[j]) { // X의 숫자가 더 크면 X의 포인터 이동
            i++;
        } 
        else {                  // Y의 숫자가 더 크면 Y의 포인터 이동
            j++;
        }
    }

    // 예외 처리
    if (answer.empty()) return "-1";
    if (answer[0] == '0') return "0";

    return answer;
}

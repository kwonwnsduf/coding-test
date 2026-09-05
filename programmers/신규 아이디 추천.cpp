#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계 & 2단계: 소문자 변환 및 허용되지 않는 문자 제거
    for (char c : new_id) {
        c = tolower(c); // 소문자 변환
        
        // 알파벳 소문자, 숫자, -, _, . 인 경우만 추가
        if (isalnum(c) || c == '-' || c == '_' || c == '.') {
            // 3단계: 마침표(.)가 연속으로 들어오는 경우 방지
            if (c == '.' && !answer.empty() && answer.back() == '.') {
                continue;
            }
            answer.push_back(c);
        }
    }

    // 4단계: 처음이나 끝에 위치한 마침표(.) 제거
    if (!answer.empty() && answer.front() == '.') {
        answer.erase(answer.begin());
    }
    if (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    // 5단계: 빈 문자열이면 "a" 대입
    if (answer.empty()) {
        answer = "a";
    }

    // 6단계: 길이가 16자 이상이면 앞 15자만 남김
    if (answer.length() >= 16) {
        answer = answer.substr(0, 15);
        if (answer.back() == '.') {
            answer.pop_back(); // 자르고 난 뒤 끝이 마침표면 제거
        }
    }

    // 7단계: 길이가 2자 이하라면 3이 될 때까지 마지막 문자 반복
    while (answer.length() < 3) {
        answer.push_back(answer.back());
    }

    return answer;
}

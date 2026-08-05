#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    // 1. O(1) 탐색을 위해 skip 문자들을 set에 저장
    unordered_set<char> skip_set(skip.begin(), skip.end());
    
    // 2. skip에 없는 알파벳만 모아 유효한 알파벳 목록 생성
    string valid = "";
    for (char c = 'a'; c <= 'z'; ++c) {
        if (skip_set.find(c) == skip_set.end()) {
            valid += c;
        }
    }
    
    // 3. s의 각 문자를 valid 기준으로 index만큼 이동
    int valid_len = valid.length();
    string answer = "";
    
    for (char c : s) {
        int pos = valid.find(c); // valid에서의 현재 위치
        int next_pos = (pos + index) % valid_len; // index만큼 이동 (순환)
        answer += valid[next_pos];
    }
    
    return answer;
}

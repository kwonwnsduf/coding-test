#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    // 각 성격 유형 캐릭터별 점수를 저장할 map
    map<char, int> score;
    
    // 선택지별 부여할 점수를 매핑 (1~7번 선택지)
    // choices[i] - 4의 절대값을 이용하면 3, 2, 1, 0, 1, 2, 3점 배점이 가능합니다.
    for (int i = 0; i < survey.size(); i++) {
        int choice = choices[i];
        
        if (choice < 4) { // 비동의 (첫 번째 문자 점수 획득)
            score[survey[i][0]] += (4 - choice);
        } else if (choice > 4) { // 동의 (두 번째 문자 점수 획득)
            score[survey[i][1]] += (choice - 4);
        }
    }
    
    string answer = "";
    
    // 1번 지표: R vs T
    answer += (score['R'] >= score['T']) ? 'R' : 'T';
    
    // 2번 지표: C vs F
    answer += (score['C'] >= score['F']) ? 'C' : 'F';
    
    // 3번 지표: J vs M
    answer += (score['J'] >= score['M']) ? 'J' : 'M';
    
    // 4번 지표: A vs N
    answer += (score['A'] >= score['N']) ? 'A' : 'N';
    
    return answer;
}

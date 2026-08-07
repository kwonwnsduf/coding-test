#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

// YYYY.MM.DD 형식의 문자열을 총 일수(day)로 변환하는 함수
int dateToDays(const string& date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1.오늘 날짜를 총 일수로 변환
    int todayDays = dateToDays(today);
    
    // 2. 약관종류별 유효기간(월)을 해시맵에 저장
    unordered_map<char, int> termMap;
    for (const string& term : terms) {
        stringstream ss(term);
        char type;
        int month;
        ss >> type >> month;
        termMap[type] = month;
    }
    
    // 3. 각 개인정보의 파기 여부 확인
    for (int i = 0; i < privacies.size(); ++i) {
        string dateStr = privacies[i].substr(0, 10);
        char type = privacies[i][11];
        
        int collectedDays = dateToDays(dateStr);
        int expireDays = collectedDays + (termMap[type] * 28);
        
        // 오늘 날짜가 만료일 이상이면 파기 대상 (1-based index 저장)
        if (todayDays >= expireDays) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    // 1. 이름과 그리움 점수를 해시맵(unordered_map)에 저장
    unordered_map<string, int> score_map;
    for (int i = 0; i < name.size(); ++i) {
        score_map[name[i]] = yearning[i];
    }
    
    // 2. 각 사진(photo)별로 인원들의 점수를 합산
    for (const auto& p : photo) {
        int total_score = 0;
        for (const auto& person : p) {
            // 해시맵에 존재하는 이름일 경우에만 점수 합산
            if (score_map.find(person) != score_map.end()) {
                total_score += score_map[person];
            }
        }
        answer.push_back(total_score);
    }
    
    return answer;
}
